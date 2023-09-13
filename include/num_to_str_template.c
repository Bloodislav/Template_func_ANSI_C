#include <math.h>
#include <stdlib.h>
#include <string.h>

#define typename(num) \
  _Generic(num, double : 'd', long double : 'L', default : 'i')

#define issigned(num)                \
  _Generic(num, unsigned             \
           : 'u', unsigned long      \
           : 'u', unsigned long long \
           : 'u', default            \
           : 's')

#ifdef T

int TEMPLATE(num_to_str, T)(T num, char* dest, int prec) {
  if (!dest) return -1;

  int error = 0;
  long double rounded = 0, div = 0;
  size_t negative = 0;

  // Checking for a negative integer
  if (issigned(num) == 's' && typename(num) == 'i') {
    union TEMPLATE(abs, T) arg_i = {0};
    arg_i.data = num;

    negative = arg_i.field.negative;
    if (arg_i.field.negative != 0) num *= -1;
  }

  // Checking for a negative floating point number (double)
  if (issigned(num) == 's' && typename(num) == 'd') {
    union TEMPLATE(dabs, T) arg_d;
    arg_d.data = num;
    negative = arg_d.field.negative;
    if (arg_d.field.negative != 0) num *= -1;
  }

  // Checking for a negative floating point number (long double)
  else if (issigned(num) == 's' && typename(num) == 'L') {
    union TEMPLATE(labs, T) arg_L;
    arg_L.data = num;
    negative = arg_L.field.negative;
    if (arg_L.field.negative != 0) num *= -1;
  }

  // if num if double (long double)
  if (typename(num) == 'd' || typename(num) == 'L') {
    div = modfl(num, &rounded);
    div *= powl(10.0, (double)prec);
    div = roundl(div) / powl(10.0, (double)prec);
  }

  // rounding for memory counting
  if (div >= 1) {
    rounded += div;
    div = modfl(rounded, &rounded);
  }

  // memory calculation and allocation
  size_t rank = TEMPLATE(rank_count, T)(num);
  size_t strlen = (rank + negative + (prec + 1) * (prec != 0) + 1);
  char* temp = malloc(sizeof(char) * strlen);

  if (temp) {
    // Substitution of necessary characters
    if (negative) *(temp) = '-';
    *(temp + negative + rank) = '.' * (prec != 0);

    // Translating the integer part of a number
    for (size_t rank_cp = rank; rank_cp; num /= 10)
      *(temp + negative + rank_cp-- - 1) = (int)fmodl(num, 10) + 48;
    
    // Translation of fractional part with rounding
    for (int prec_cp = 1; prec_cp <= prec; prec_cp++) {
      if (div < 0.9 && div > 0.8999) div = roundl(div * 10.0) / 10.0;
      div = modfl((div)*10.L, &rounded);
      *(temp + negative + rank + prec_cp) = (int)rounded + 48;
    }

    // '\0'
    *(temp + strlen - 1) = 0;
    
    // Memory copying
    memcpy(dest, temp, strlen);

    // Clearing a temporary variable
    free(temp);
  } else
    error = -1;

  return error;
}

// counting the number of digits in an integer part
int TEMPLATE(rank_count, T)(T num) {
  int result = 1;
  while ((num /= 10) >= 1) result++;
  return result;
}

#endif