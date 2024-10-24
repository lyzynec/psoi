#include "pls.h"
#include <assert.h>

#include "genmath.h"

/**
 * @brief Compute the breakpoints of a line segment.
 * 
 * @param z The current position.
 * @param z_upper The upper bound.
 * @param z_lower The lower bound.
 * @param direction The direction of the line segment.
 * @param result The result vector.
 * @param n The size of the vectors.
 * 
 * @return 0 on success, -1 on error.
 */
int breakpoints(
    const PSOI_FLOAT *const z,
    const PSOI_FLOAT *const z_upper,
    const PSOI_FLOAT *const z_lower,
    const PSOI_FLOAT *const direction,
    PSOI_FLOAT *const result,
    size_t n
) {
    assert(z != NULL);
    assert(z_upper != NULL);
    assert(z_lower != NULL);
    assert(direction != NULL);
    assert(result != NULL);

    vector_fill(result, n, INFINITY);

    for (size_t i = 0; i < n; i++) {
        if (direction[i] < 0 && z_upper[i] < INFINITY) {
            result[i] = (z[i] - z_upper[i]) / direction[i];
        } else if (direction[i] > 0 && z_lower[i] > -INFINITY) {
            result[i] = (z[i] - z_lower[i]) / direction[i];
        }
    }

    return 0;
}

/**
 * @brief Compute the maximum alpha value.
 * 
 * @param breakpoints The breakpoints.
 * @param n The size of the vector.
 * @param alpha The result scalar.
 * 
 * @return 0 on success, -1 on error.
 */
int max_alpha(
    const PSOI_FLOAT *const breakpoints,
    size_t n,
    PSOI_FLOAT *const alpha
) {
    assert(breakpoints != NULL);
    assert(alpha != NULL);

    PSOI_FLOAT min_alpha = INFINITY;

    for (size_t i = 0; i < n; i++) {
        min_alpha = MIN(min_alpha, breakpoints[i]);
    }

    *alpha = min_alpha;

    return 0;
}