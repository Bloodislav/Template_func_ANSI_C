#ifndef ALL_POSSIBLE_VARS_H_
#define ALL_POSSIBLE_VARS_H_

#include <endian.h>

#define CAT(X, Y) X##_##Y
#define TEMPLATE(X, Y) CAT(X, Y)

typedef long long int64;
typedef unsigned long uint32;
typedef unsigned long long uint64;
typedef long double double128;

#ifdef T
#undef T
#endif
#define T int
#include "num_to_str_template.h"
union TEMPLATE(abs, T) {
  T data;
  struct {
#if __BYTE_ORDER == __BIG_ENDIAN
    unsigned int negative : 1;
    unsigned int other : (8 * sizeof(T) - 1);
#endif 
#if __BYTE_ORDER == __LITTLE_ENDIAN
    unsigned int other : (8 * sizeof(T) - 1);
    unsigned int negative : 1;
#endif 
  } field;
};

#ifdef T
#undef T
#endif
#define T long
#include "num_to_str_template.h"
union TEMPLATE(abs, T) {
  T data;
  struct {
#if __BYTE_ORDER == __BIG_ENDIAN
    unsigned int negative : 1;
    unsigned long int other : (8 * sizeof(T) - 1);
#endif 
#if __BYTE_ORDER == __LITTLE_ENDIAN
    unsigned long int other : (8 * sizeof(T) - 1);
    unsigned int negative : 1;
#endif 
  } field;
};

#ifdef T
#undef T
#endif
#define T int64
#include "num_to_str_template.h"
union TEMPLATE(abs, T) {
  T data;
  struct {
#if __BYTE_ORDER == __BIG_ENDIAN
    unsigned int negative : 1;
    unsigned long int other : (8 * sizeof(T) - 1);
#endif 
#if __BYTE_ORDER == __LITTLE_ENDIAN
    unsigned long int other : (8 * sizeof(T) - 1);
    unsigned int negative : 1;
#endif 
  } field;
};

#ifdef T
#undef T
#endif
#define T unsigned
#include "num_to_str_template.h"
union TEMPLATE(abs, T) {
  T data;
  struct {
#if __BYTE_ORDER == __BIG_ENDIAN
    unsigned int negative : 1;
    unsigned int other : (8 * sizeof(T) - 1);
#endif 
#if __BYTE_ORDER == __LITTLE_ENDIAN
    unsigned int other : (8 * sizeof(T) - 1);
    unsigned int negative : 1;
#endif 
  } field;
};

#ifdef T
#undef T
#endif
#define T uint32
#include "num_to_str_template.h"
union TEMPLATE(abs, T) {
  T data;
  struct {
#if __BYTE_ORDER == __BIG_ENDIAN
    unsigned int negative : 1;
    unsigned long int other : (8 * sizeof(T) - 1);
#endif 
#if __BYTE_ORDER == __LITTLE_ENDIAN
    unsigned long int other : (8 * sizeof(T) - 1);
    unsigned int negative : 1;
#endif 
  } field;
};

#ifdef T
#undef T
#endif
#define T uint64
#include "num_to_str_template.h"
union TEMPLATE(abs, T) {
  T data;
  struct {
#if __BYTE_ORDER == __BIG_ENDIAN
    unsigned int negative : 1;
    unsigned long int other : (8 * sizeof(T) - 1);
#endif 
#if __BYTE_ORDER == __LITTLE_ENDIAN
    unsigned long int other : (8 * sizeof(T) - 1);
    unsigned int negative : 1;
#endif 
  } field;
};

#ifdef T
#undef T
#endif
#define T double
#include "num_to_str_template.h"
union TEMPLATE(abs, T) {
  T data;
  struct {
#if __BYTE_ORDER == __BIG_ENDIAN
    unsigned int negative : 1;
    unsigned int exponent : 11;
    unsigned int mantissa0 : 20;
    unsigned int mantissa1 : 32;
#endif
#if __BYTE_ORDER == __LITTLE_ENDIAN
#if __FLOAT_WORD_ORDER == __BIG_ENDIAN
    unsigned int mantissa0 : 20;
    unsigned int exponent : 11;
    unsigned int negative : 1;
    unsigned int mantissa1 : 32;
#else
    unsigned int mantissa1 : 32;
    unsigned int mantissa0 : 20;
    unsigned int exponent : 11;
    unsigned int negative : 1;
#endif
#endif 
  } field;
};

#ifdef T
#undef T
#endif
#define T double128
#include "num_to_str_template.h"
union TEMPLATE(abs, T) {
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

#endif