#ifdef T

#include <endian.h>  

union TEMPLATE(abs, T) {
  T data;
  struct {
#if __BYTE_ORDER == __BIG_ENDIAN
    unsigned int negative : 1;
    unsigned int other : (sizeof(T) - 1);
#endif /* Big endian.  */
#if __BYTE_ORDER == __LITTLE_ENDIAN
    unsigned int other : (sizeof(T) - 1);
    unsigned int negative : 1;
#endif /* Little endian.  */
  } znac;
};

int TEMPLATE(num_to_str, T)(T num, char *dest, int prec);
int TEMPLATE(rank_count, T)(T num);

#endif