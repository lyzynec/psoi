#ifndef __PSOI_LINALG_H__
#define __PSOI_LINALG_H__

#include "vector.h"
#include "symmatrix.h"

/**
    * @brief Multiply a symmetric matrix by a vector.
    *
    * @param matrix The matrix.
    * @param vector The vector.
    * @param result The result vector.
    * @param n The size of the matrix and vector.
    *
    * @return 0 on success, -1 on error.
    */
int mul_symmat_vec(
    const PSOI_FLOAT *const matrix,
    const PSOI_FLOAT *const vector,
    PSOI_FLOAT *const result,
    size_t n
);

/**
    * @brief Multiply a symmetric matrix by a vector at a specific row.
    *
    * @param matrix The matrix.
    * @param vector The vector.
    * @param n The size of the matrix and vector.
    * @param row The row.
    * @param result The result scalar.
    *
    * @return 0 on success, -1 on error.
    */
int mul_symmat_vec_at_row(
    const PSOI_FLOAT *const matrix,
    const PSOI_FLOAT *const vector,
    size_t n,
    size_t row,
    PSOI_FLOAT *const result
);

/**
    * @brief Quadratic product of a symmetric matrix and a vector as in `v^T M v`.
    *
    * @param matrix The matrix.
    * @param vector The vector.
    * @param helper A helper vector for buffer.
    * @param n The size of the matrix and vector.
    * @param result The result scalar.
    *
    * @return 0 on success, -1 on error.
    */
int quad_mul_symmat_vec(
    const PSOI_FLOAT *const matrix,
    const PSOI_FLOAT *const vector,
    PSOI_FLOAT *const helper,
    size_t n,
    PSOI_FLOAT *const result
    
);

#endif // __PSOI_LINALG_H__
