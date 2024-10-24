#ifndef __PSOI_GRADIENT_H__
#define __PSOI_GRADIENT_H__

#include "linalg/linalg.h"

int gradient(
    const PSOI_FLOAT *const H,
    const PSOI_FLOAT *const h,
    const PSOI_FLOAT *const z,
    PSOI_FLOAT *const result,
    size_t n
);

int gradient_at(
    const PSOI_FLOAT *const H,
    const PSOI_FLOAT *const h,
    const PSOI_FLOAT *const z,
    PSOI_FLOAT *const result,
    size_t n,
    size_t i
);

int gradient_free(
    const PSOI_FLOAT *const H,
    const PSOI_FLOAT *const h,
    const PSOI_FLOAT *const z,
    const PSOI_FLOAT *const z_upper,
    const PSOI_FLOAT *const z_lower,
    const PSOI_FLOAT *const gradient,
    PSOI_FLOAT *const result,
    size_t n
);

int gradient_chopped(
    const PSOI_FLOAT *const H,
    const PSOI_FLOAT *const h,
    const PSOI_FLOAT *const z,
    const PSOI_FLOAT *const z_upper,
    const PSOI_FLOAT *const z_lower,
    const PSOI_FLOAT *const gradient,
    PSOI_FLOAT *const result,
    size_t n
);

int gradient_projected(
    const PSOI_FLOAT *const H,
    const PSOI_FLOAT *const h,
    const PSOI_FLOAT *const z,
    const PSOI_FLOAT *const z_upper,
    const PSOI_FLOAT *const z_lower,
    const PSOI_FLOAT *const gradient,
    PSOI_FLOAT *const result,
    size_t n
);

#endif // __PSOI_GRADIENT_H__
