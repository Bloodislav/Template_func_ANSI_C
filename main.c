#include <stdio.h>

#include "all_variable.h"

int main() {
  int num_0 = 1;
  char str_0[40];

  TEMPLATE(num_to_str, int)(num_0, str_0, 0);
  printf("num(%%d): %d\n", num_0);
  printf("num(%%s): %s\n", str_0);

  double num_1 = 10.99;
  char str_1[40];

  TEMPLATE(num_to_str, double)(num_1, str_1, 6);
  printf("num(%%lf): %.6lf\n", num_1);
  printf("num(%%s) : %s\n", str_1);

  int64 num_2 = -100000000000000000;
  char str_2[40];

  TEMPLATE(num_to_str, double)(num_2, str_2, 0);
  printf("num(%%lld): %lld\n", num_2);
  printf("num(%%s)  : %s\n", str_2);

  long double num_3 = .3;
  char str_3[40];

  TEMPLATE(num_to_str, double)(num_3, str_3, 6);
  printf("num(%%Lf): %Lf\n", num_3);
  printf("num(%%s) : %s\n", str_3);

  return 0;
}