#ifndef __PSOI_GENMATH_H__
#define __PSOI_GENMATH_H__

#include <math.h>

#define SIGNUM(x) ((x) >= 0 ? 1 : -1)

#define FABS(x) _Generic((x), \
    float: fabsf,            \
    double: fabs,            \
    long double: fabsl       \
)(x)

#define FSQRT(x) _Generic((x), \
    float: sqrtf,            \
    double: sqrt,            \
    long double: sqrtl       \
)(x)

#define FMAX(a, b) _Generic((a), \
    float: fmaxf,               \
    double: fmax,               \
    long double: fmaxl          \
)(a, b)

#define FMIN(a, b) _Generic((a), \
    float: fminf,               \
    double: fmin,               \
    long double: fminl          \
)(a, b)

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

#endif // __PSOI_GENMATH_H__