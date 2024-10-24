#ifndef __PSOI_GRADIENT_H__
#define __PSOI_GRADIENT_H__

#include "linalg/linalg.h"

/**
 * @brief Compute the gradient of the quadratic function
 * 
 * @param H The Hessian matrix
 * @param h The linear term
 * @param z The point at which to evaluate the gradient
 * @param result The result of the gradient
 * @param n The size of the matrices
 * 
 * @return 0 if successful, -1 otherwise
 */
int gradient(
    const PSOI_FLOAT *const H,
    const PSOI_FLOAT *const h,
    const PSOI_FLOAT *const z,
    PSOI_FLOAT *const result,
    size_t n
);

/**
 * @brief Compute the gradient of the quadratic function at a specific index
 * 
 * @param H The Hessian matrix
 * @param h The linear term
 * @param z The point at which to evaluate the gradient
 * @param result The result of the gradient
 * @param n The size of the matrices
 * @param i The index at which to evaluate the gradient
 * 
 * @return 0 if successful, -1 otherwise
 */
int gradient_at(
    const PSOI_FLOAT *const H,
    const PSOI_FLOAT *const h,
    const PSOI_FLOAT *const z,
    PSOI_FLOAT *const result,
    size_t n,
    size_t i
);

/**
 * @brief Compute the Free Gradient of the quadratic function
 * 
 * @param H The Hessian matrix
 * @param h The linear term
 * @param z The point at which to evaluate the gradient
 * @param z_upper The upper bound of the z variables
 * @param z_lower The lower bound of the z variables
 * @param gradient The gradient of the function
 * 
 * @return 0 if successful, -1 otherwise
 */
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

/**
 * @brief Compute the Chopped Gradient of the quadratic function
 * 
 * @param H The Hessian matrix
 * @param h The linear term
 * @param z The point at which to evaluate the gradient
 * @param z_upper The upper bound of the z variables
 * @param z_lower The lower bound of the z variables
 * @param gradient The gradient of the function
 * 
 * @return 0 if successful, -1 otherwise
 */
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

/**
 * @brief Compute the Projected Gradient of the quadratic function
 * 
 * @param H The Hessian matrix
 * @param h The linear term
 * @param z The point at which to evaluate the gradient
 * @param z_upper The upper bound of the z variables
 * @param z_lower The lower bound of the z variables
 * @param gradient The gradient of the function
 * 
 * @return 0 if successful, -1 otherwise
 */
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
