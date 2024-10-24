#include "givens.h"

#include <math.h>

#define SIGNUM(x) ((x) >= 0 ? 1 : -1)
#define ABS(x) _Generic((x), \
    float: fabsf,            \
    double: fabs,            \
    long double: fabsl       \
)(x)

#define SQRT(x) _Generic((x), \
    float: sqrtf,            \
    double: sqrt,            \
    long double: sqrtl       \
)(x)

int givens_rotation(
    PSOI_FLOAT a,
    PSOI_FLOAT b,
    PSOI_FLOAT *const c,
    PSOI_FLOAT *const s,
    PSOI_FLOAT *const r
) {

    PSOI_FLOAT t, u;

    if (b == 0) {
        *c = SIGNUM(a);
        *s = 0;
        *r = ABS(a);
    } else if (a == 0) {
        *c = 0;
        *s = -SIGNUM(b);
        *r = ABS(b); 
    } else if (ABS(a) > ABS(b)) {
        t = b / a;
        u = SIGNUM(a) * SQRT(1 + t * t);
        *c = 1 / u;
        *s = -(*c) * t;
        *r = a * u;
    } else {
        t = a / b;
        u = SIGNUM(b) * SQRT(1 + t * t);
        *c = t / u;
        *s = -1 / u;
        *r = b * u;
    }

    return 0;
}
