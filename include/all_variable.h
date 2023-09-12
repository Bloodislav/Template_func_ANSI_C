#ifndef ALL_POSSIBLE_VARS_H_
#define ALL_POSSIBLE_VARS_H_

#define CAT(X, Y) X##_##Y
#define TEMPLATE(X, Y) CAT(X, Y)

typedef long long int64;
typedef unsigned long uint32;
typedef unsigned long long uint64;

#ifdef T
#undef T
#endif
#define T int
#include "num_to_str_template.h"

#ifdef T
#undef T
#endif
#define T long
#include "num_to_str_template.h"

#ifdef T
#undef T
#endif
#define T int64
#include "num_to_str_template.h"

#ifdef T
#undef T
#endif
#define T unsigned
#include "num_to_str_template.h"

#ifdef T
#undef T
#endif
#define T uint32
#include "num_to_str_template.h"

#ifdef T
#undef T
#endif
#define T uint64
#include "num_to_str_template.h"

#ifdef T
#undef T
#endif
#define T double
#include "num_to_str_template.h"

#endif