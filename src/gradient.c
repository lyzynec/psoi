#include "gradient.h"

#include <assert.h>

#include "genmath.h"

int gradient(
    const PSOI_FLOAT *const H,
    const PSOI_FLOAT *const h,
    const PSOI_FLOAT *const z,
    PSOI_FLOAT *const result,
    size_t n
) {

    assert(n > 0);
    assert(H != NULL);
    assert(h != NULL);
    assert(z != NULL);
    assert(result != NULL);

    if (!mul_symmat_vec(H, z, result, n)) {
        return -1;
    }

    if (vector_addassign(result, h, n)) {
        return -1;
    }

    return 0;
}

int gradient_at(
    const PSOI_FLOAT *const H,
    const PSOI_FLOAT *const h,
    const PSOI_FLOAT *const z,
    PSOI_FLOAT *const result,
    size_t n,
    size_t i
) {
    
    assert(n > 0);
    assert(H != NULL);
    assert(h != NULL);
    assert(z != NULL);
    assert(result != NULL);

    if (i >= n) {
        return -1;
    }

    if (!mul_symmat_vec_at_row(H, z, n, i, result)) {
        return -1;
    }

    *result += h[i];

    return 0;
}

int gradient_free(
    const PSOI_FLOAT *const H,
    const PSOI_FLOAT *const h,
    const PSOI_FLOAT *const z,
    const PSOI_FLOAT *const z_upper,
    const PSOI_FLOAT *const z_lower,
    const PSOI_FLOAT *const gradient,
    PSOI_FLOAT *const result,
    size_t n
) {

    assert(n > 0);
    assert(H != NULL);
    assert(h != NULL);
    assert(z != NULL);
    assert(z_upper != NULL);
    assert(z_lower != NULL);
    assert(result != NULL);

    vector_fill(result, n, 0);

    if (gradient != NULL) {
        for (size_t i = 0; i < n; i++) {
            if (z[i] < z_upper[i] && z[i] > z_lower[i]) {
                result[i] = gradient[i];
            }
        }
    } else {
        for (size_t i = 0; i < n; i++) {
            if (z[i] < z_upper[i] && z[i] > z_lower[i]) {
                if (!gradient_at(H, h, z, &result[i], n, i)) {
                    return -1;
                }
            }
        }
    }

    return 0;
}

int gradient_chopped(
    const PSOI_FLOAT *const H,
    const PSOI_FLOAT *const h,
    const PSOI_FLOAT *const z,
    const PSOI_FLOAT *const z_upper,
    const PSOI_FLOAT *const z_lower,
    const PSOI_FLOAT *const gradient,
    PSOI_FLOAT *const result,
    size_t n
) {

    assert(n > 0);
    assert(H != NULL);
    assert(h != NULL);
    assert(z != NULL);
    assert(z_upper != NULL);
    assert(z_lower != NULL);
    assert(result != NULL);
    
    vector_fill(result, n, 0);

    if (gradient != NULL) {
        for (size_t i = 0; i < n; i++) {
            if (z[i] >= z_upper[i]) {
                result[i] = MAX(0, gradient[i]);
            } else if (z[i] <= z_lower[i]) {
                result[i] = MIN(0, gradient[i]);
            }
        }
    } else {
        for (size_t i = 0; i < n; i++) {
            if (z[i] >= z_upper[i]) {
                if (!gradient_at(H, h, z, &result[i], n, i)) {
                    return -1;
                }
                result[i] = MAX(0, result[i]);
            } else if (z[i] <= z_lower[i]) {
                if (!gradient_at(H, h, z, &result[i], n, i)) {
                    return -1;
                }
                result[i] = MIN(0, result[i]);
            }
        }
    }

    return 0;
}

int gradient_projected(
    const PSOI_FLOAT *const H,
    const PSOI_FLOAT *const h,
    const PSOI_FLOAT *const z,
    const PSOI_FLOAT *const z_upper,
    const PSOI_FLOAT *const z_lower,
    const PSOI_FLOAT *const gradient,
    PSOI_FLOAT *const result,
    size_t n
) {

    assert(n > 0);
    assert(H != NULL);
    assert(h != NULL);
    assert(z != NULL);
    assert(z_upper != NULL);
    assert(z_lower != NULL);
    assert(gradient != NULL);
    assert(result != NULL);

    for (size_t i = 0; i < n; i++) {
        if (z[i] >= z_upper[i]) {
            result[i] = MAX(0, gradient[i]);
        } else if (z[i] <= z_lower[i]) {
            result[i] = MIN(0, gradient[i]);
        } else {
            result[i] = gradient[i];
        }
    }

}
