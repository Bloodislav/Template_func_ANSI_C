#ifdef T

// TODO: Подумать об определении макросов
union TEMPLATE(abs, T) {
  T data;
  struct {
#if __BYTE_ORDER == __BIG_ENDIAN
    unsigned int negative : 1;
#if (T == double128)
    unsigned long int other0 : 64;
    unsigned long int other1 : 63;
#else
    unsigned long int other0 : (8 * sizeof(T) - 1);
#endif
#endif
#if __BYTE_ORDER == __LITTLE_ENDIAN
#if (T == double128)
    unsigned long int other0 : 64;
    unsigned long int other1 : 63;
#else
    unsigned long int other0 : (8 * sizeof(T) - 1);
#endif
    unsigned int negative : 1;
#endif
  } field;
};

union TEMPLATE(dabs, T) {
  T data;
  struct {
#if __BYTE_ORDER == __BIG_ENDIAN
    unsigned int negative : 1;
    unsigned long int other : 63;
#endif
#if __BYTE_ORDER == __LITTLE_ENDIAN
#if __FLOAT_WORD_ORDER == __BIG_ENDIAN
    unsigned int mantissa0 : 20;
    unsigned int exponent : 11;
    unsigned int negative : 1;
    unsigned int mantissa1 : 32;
#else
    unsigned long int other : 63;
    unsigned int negative : 1;
#endif
#endif
  } field;
};

union TEMPLATE(labs, T) {
  T data;
  struct {
#if __BYTE_ORDER == __BIG_ENDIAN
    unsigned int negative : 1;
    unsigned int exponent : 15;
    unsigned int empty : 16;
    unsigned int mantissa0 : 32;
    unsigned int mantissa1 : 32;
#endif
#if __BYTE_ORDER == __LITTLE_ENDIAN
#if __FLOAT_WORD_ORDER == __BIG_ENDIAN
    unsigned int exponent : 15;
    unsigned int negative : 1;
    unsigned int empty : 16;
    unsigned int mantissa0 : 32;
    unsigned int mantissa1 : 32;
#else
    unsigned int mantissa1 : 32;
    unsigned int mantissa0 : 32;
    unsigned int exponent : 15;
    unsigned int negative : 1;
    unsigned int empty : 16;
#endif
#endif
  } field;
};

int TEMPLATE(num_to_str, T)(T num, char *dest, int prec);
int TEMPLATE(rank_count, T)(T num);

#endif