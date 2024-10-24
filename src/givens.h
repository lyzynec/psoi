#ifndef __PSOI_GIVENS_H__
#define __PSOI_GIVENS_H__

#include "general.h"

/**
 * @brief Compute the Givens rotation.
 * 
 * @param a The first element.
 * @param b The second element.
 * @param c The cosine of the rotation.
 * @param s The sine of the rotation.
 * @param r The result of the rotation.
 * 
 * @return 0 on success, -1 on error.
 */
int givens_rotation(
    PSOI_FLOAT a,
    PSOI_FLOAT b,
    PSOI_FLOAT *const c,
    PSOI_FLOAT *const s,
    PSOI_FLOAT *const r
);

#endif // __PSOI_GIVENS_H__