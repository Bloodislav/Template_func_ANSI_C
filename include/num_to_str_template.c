#include <math.h>
#include <stdlib.h>
#include <string.h>

#define typename(num) \
  _Generic(num, double : "double", long double : "double", default : "int")

#define issigned(num)         \
  _Generic(num, unsigned      \
           : "unsigned", unsigned long  \
           : "unsigned", unsigned long long  \
           : "unsigned", default \
           : "signed")
#ifdef T

int TEMPLATE(num_to_str, T)(T num, char* dest, int prec) {
  if (!dest) return -1;

  int error = 0;
  long double rounded = 0, div = 0;
  size_t negative = 0;
  
  union TEMPLATE(abs, T) arg;
  arg.data = num;

  if (strcmp(issigned(num), "signed") == 0) {
    negative = arg.field.negative;
    
    if (arg.field.negative != 0) num *= -1;
  }

  if (strcmp(typename(num), "double") == 0) {
    div = modfl(num, &rounded);
    div *= powl(10.0, (double)prec);
    div = roundl(div) / powl(10.0, (double)prec);
  }
  
  if (div >= 1) {
    rounded += div;
    div = modfl(rounded, &rounded);
  }

  size_t rank = TEMPLATE(rank_count, T)(num);
  size_t strlen = (rank + negative + (prec + 1) * (prec != 0) + 1);
  char* temp = malloc(sizeof(char) * strlen);

  if (temp) {
    if (negative) *(temp) = '-';
    *(temp + negative + rank) = '.' * (prec != 0);

    for (size_t rank_cp = rank; rank_cp; num /= 10)
      *(temp + negative + rank_cp-- - 1) = (int)fmodl(num, 10) + 48;

    for (int prec_cp = 1; prec_cp <= prec; prec_cp++) {
      if (div < 0.9 && div > 0.8999) div = roundl(div * 10.0) / 10.0;
      div = modfl((div) * 10.L, &rounded);
      *(temp + negative + rank + prec_cp) = (int)rounded + 48;
    }

    *(temp + strlen - 1) = 0;

    strncpy(dest, temp, strlen);

    free(temp);
  } else
    error = -1;

  return error;
}

int TEMPLATE(rank_count, T)(T num) {
  int result = 1;
  while ((num /= 10) >= 1) result++;
  return result;
}

#endif