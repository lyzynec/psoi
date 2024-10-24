#include "givens.h"

#include "genmath.h"

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
        *r = FABS(a);
    } else if (a == 0) {
        *c = 0;
        *s = -SIGNUM(b);
        *r = FABS(b); 
    } else if (FABS(a) > FABS(b)) {
        t = b / a;
        u = SIGNUM(a) * FSQRT(1 + t * t);
        *c = 1 / u;
        *s = -(*c) * t;
        *r = a * u;
    } else {
        t = a / b;
        u = SIGNUM(b) * FSQRT(1 + t * t);
        *c = t / u;
        *s = -1 / u;
        *r = b * u;
    }

    return 0;
}
