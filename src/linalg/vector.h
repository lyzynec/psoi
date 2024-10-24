#ifndef __PSOI_VECTOR_H__
#define __PSOI_VECTOR_H__

#include "../general.h"

#include <stddef.h>

/* SET - GET Functions #######################################################*/

/*
    * @brief Set a value in a vector.
    *
    * @param vector The vector.
    * @param n The size of the vector.
    * @param i The index of the value to set.
    * @param value The value to set.
    *
    * @return 0 on success, -1 on error.
    */
int vector_set(
    PSOI_FLOAT *const vector,
    size_t n,
    size_t i,
    PSOI_FLOAT value
);

/*
    * @brief Get a value from a vector.
    *
    * @param vector The vector.
    * @param n The size of the vector.
    * @param i The index of the value to get.
    * @param value The value to get.
    *
    * @return 0 on success, -1 on error.
    */
int vector_get(
    const PSOI_FLOAT *const vector,
    size_t n,
    size_t i,
    PSOI_FLOAT *const value
);

/* Arithmetic Operations #####################################################*/

/*
    * @brief Add two vectors.
    *
    * @param vector The vector to add to.
    * @param other The vector to add.
    * @param n The size of the vectors.
    *
    * @return 0 on success, -1 on error.
    */
int vector_addassign(
    PSOI_FLOAT *const vector,
    const PSOI_FLOAT *const other,
    size_t n
);

/*
    * @brief Subtract two vectors.
    *
    * @param vector The vector to subtract from.
    * @param other The vector to subtract.
    * @param n The size of the vectors.
    *
    * @return 0 on success, -1 on error.
    */
int vector_subassign(
    PSOI_FLOAT *const vector,
    const PSOI_FLOAT *const other,
    size_t n
);

/*
    * @brief Multiply a vector by a scalar.
    *
    * @param vector The vector to multiply.
    * @param n The size of the vector.
    * @param scalar The scalar to multiply by.
    *
    * @return 0 on success, -1 on error.
    */
int vector_mulassign(
    PSOI_FLOAT *const vector,
    size_t n,
    PSOI_FLOAT scalar
);

/* Memory Operations #########################################################*/

/*
    * @brief Copy a vector.
    *
    * @param dst The destination vector.
    * @param src The source vector.
    * @param n The size of the vectors.
    *
    * @return 0 on success, -1 on error.
    */
int vector_copy(
    PSOI_FLOAT *const dst,
    const PSOI_FLOAT *const src,
    size_t n
);

/*
    * @brief Fill a vector with a value.
    *
    * @param vector The vector.
    * @param n The size of the vector.
    * @param value The value to fill the vector with.
    *
    * @return 0 on success, -1 on error.
    */
int vector_fill(
    PSOI_FLOAT *const vector,
    size_t n,
    PSOI_FLOAT value
);

/* Vector Operations #########################################################*/

/*
    * @brief Compute the dot product of two vectors.
    *
    * @param vector The first vector.
    * @param other The second vector.
    * @param n The size of the vectors.
    * @param result The result of the dot product.
    *
    * @return 0 on success, -1 on error.
    */
int vector_dot(
    const PSOI_FLOAT *const vector,
    const PSOI_FLOAT *const other,
    size_t n,
    PSOI_FLOAT *const result
);

/**
 * @brief Bound the values of a vector.
 * 
 * @param vector The vector.
 * @param upper The upper bound.
 * @param lower The lower bound.
 * @param n The size of the vector.
 * 
 * @return 0 on success, -1 on error.
 */
int vector_saturate(
    PSOI_FLOAT *const vector,
    const PSOI_FLOAT *const upper,
    const PSOI_FLOAT *const lower,
    size_t n
);

/**
 * @brief Compute the euclidean norm of a vector.
 * 
 * @param vector The vector.
 * @param n The size of the vector.
 * @param result The result of the norm.
 * 
 * @return 0 on success, -1 on error.
 */
int vector_euclid_norm(
    const PSOI_FLOAT *const vector,
    size_t n,
    PSOI_FLOAT *const result
);

#endif // __PSOI_VECTOR_H__
