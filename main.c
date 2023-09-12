#include <stdio.h>

#include "all_variable.h"

int main() {
  int num_0 = -1;
  char str_0[40];

  TEMPLATE(num_to_str, int)(num_0, str_0, 0);
  printf("\n int \n");
  printf("num(%%d): %d\n", num_0);
  printf("num(%%s): %s\n", str_0);

  long num_1 = -1;
  char str_1[40];

  TEMPLATE(num_to_str, long)(num_1, str_1, 0);
  printf("\n long \n");
  printf("num(%%ld): %ld\n", num_1);
  printf("num(%%s) : %s\n", str_1);

  int64 num_2 = -1000000000000000;
  char str_2[40];

  TEMPLATE(num_to_str, int64)(num_2, str_2, 0);
  printf("\n long long int \n");
  printf("num(%%lld): %lld\n", num_2);
  printf("num(%%s)  : %s\n", str_2);

  unsigned num_3 = 100000000;
  char str_3[40];

  TEMPLATE(num_to_str, unsigned)(num_3, str_3, 0);
  printf("\n unsigned \n");
  printf("num(%%u): %u\n", num_3);
  printf("num(%%s): %s\n", str_3);
  
  uint32 num_4 = 100000000;
  char str_4[40];

  TEMPLATE(num_to_str, uint32)(num_4, str_4, 0);
  printf("\n unsigned long \n");
  printf("num(%%lu): %lu\n", num_4);
  printf("num(%%s) : %s\n", str_4);
  
  uint64 num_5 = 100000000;
  char str_5[40];

  TEMPLATE(num_to_str, uint64)(num_5, str_5, 0);
  printf("\n unsigned long long \n");
  printf("num(%%lu): %llu\n", num_5);
  printf("num(%%s) : %s\n", str_5);
  
  double num_6 = -10.99;
  char str_6[40];

  TEMPLATE(num_to_str, double)(num_6, str_6, 6);
  printf("\n double \n");
  printf("num(%%lf): %.6lf\n", num_6);
  printf("num(%%s) : %s\n", str_6);

  long double num_7 = -.3;
  char str_7[40];

  TEMPLATE(num_to_str, double128)(num_7, str_7, 6);
  printf("\n long double \n");
  printf("num(%%Lf): %Lf\n", num_7);
  printf("num(%%s) : %s\n", str_7);


  return 0;
}
