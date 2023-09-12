#include "all_variable.h"

#ifdef T
#undef T
#endif
#define T int
#include "num_to_str_template.c"

#ifdef T
#undef T
#endif
#define T long
#include "num_to_str_template.c"

#ifdef T
#undef T
#endif
#define T int64
#include "num_to_str_template.c"

#ifdef T
#undef T
#endif
#define T unsigned
#include "num_to_str_template.c"

#ifdef T
#undef T
#endif
#define T uint32
#include "num_to_str_template.c"

#ifdef T
#undef T
#endif
#define T uint64
#include "num_to_str_template.c"

#ifdef T
#undef T
#endif
#define T double
#include "num_to_str_template.c"

#ifdef T
#undef T
#endif
#define T double128
#include "num_to_str_template.c"