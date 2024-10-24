#include "vector.h"
#include <string.h>

#include "../genmath.h"

int vector_set(
    PSOI_FLOAT *const vector,
    size_t n,
    size_t i,
    PSOI_FLOAT value
) {
    if (i >= n) {
        return -1;
    }

    vector[i] = value;

    return 0;
}

int vector_get(
    const PSOI_FLOAT *const vector,
    size_t n,
    size_t i,
    PSOI_FLOAT *const value
) {
    if (i >= n) {
        return -1;
    }

    *value = vector[i];
    return 0;
}

int vector_addassign(
    PSOI_FLOAT *const vector,
    const PSOI_FLOAT *const other,
    size_t n
) {
    for (size_t i = 0; i < n; i++) {
        vector[i] += other[i];
    }

    return 0;
}

int vector_subassign(
    PSOI_FLOAT *const vector,
    const PSOI_FLOAT *const other,
    size_t n
) {
    for (size_t i = 0; i < n; i++) {
        vector[i] -= other[i];
    }

    return 0;
}

int vector_mulassign(
    PSOI_FLOAT *const vector,
    size_t n,
    PSOI_FLOAT scalar
) {
    for (size_t i = 0; i < n; i++) {
        vector[i] *= scalar;
    }

    return 0;
}

int vector_copy(
    PSOI_FLOAT *const dst,
    const PSOI_FLOAT *const src,
    size_t n
) {
    memcpy(dst, src, n * sizeof(PSOI_FLOAT));

    return 0;
}

int vector_fill(
    PSOI_FLOAT *const vector,
    size_t n,
    PSOI_FLOAT value
) {
    memset(vector, value, n * sizeof(PSOI_FLOAT));

    return 0;
}

int vector_dot(
    const PSOI_FLOAT *const vector,
    const PSOI_FLOAT *const other,
    size_t n,
    PSOI_FLOAT *const result
) {
    PSOI_FLOAT res_loc = 0;
    
    for (size_t i = 0; i < n; i++) {
        res_loc += vector[i] * other[i];
    }

    *result = res_loc;

    return 0;
}

int vector_saturate(
    PSOI_FLOAT *const vector,
    const PSOI_FLOAT *const upper,
    const PSOI_FLOAT *const lower,
    size_t n
) {
    for (size_t i = 0; i < n; i++) {
        vector[i] = MAX(MIN(vector[i], upper[i]), lower[i]);
    }

    return 0;
}

int vector_euclid_norm(
    const PSOI_FLOAT *const vector,
    size_t n,
    PSOI_FLOAT *const result
) {
    PSOI_FLOAT res_loc = 0;
    if (!vector_dot(vector, vector, n, &res_loc)) {
        return -1;
    }

    res_loc = FSQRT(res_loc);

    *result = res_loc;

    return 0;
}
