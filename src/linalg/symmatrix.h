#ifndef __PSOI_SYMMATRIX_H__
#define __PSOI_SYMMATRIX_H__

#include "../general.h"

#include <stddef.h>

#define SYMMATRIX_DATALEN(n) ((n) * ((n) + 1) / 2)
#define SYMMATRIX_ROW_OFFSET(n, row) ((row) * (n) - ((row)*(row) - (row))/2)
#define SYMMATRIX_INDEX(n, row, col) ((row) < (col) ? SYMMATRIX_ROW_OFFSET(n, row) + (col) - (row) : SYMMATRIX_ROW_OFFSET(n, col) + (row) - (col))

/* SET - GET Functions #######################################################*/

/*
    * @brief Set a value in a symmetric matrix.
    *
    * @param matrix The matrix.
    * @param n The size of the matrix.
    * @param row The row index of the value to set.
    * @param col The column index of the value to set.
    * @param value The value to set.
    *
    * @return 0 on success, -1 on error.
    */
int symmatrix_set(PSOI_FLOAT *const matrix, size_t n, size_t row, size_t col, PSOI_FLOAT value);

/*
    * @brief Get a value from a symmetric matrix.
    *
    * @param matrix The matrix.
    * @param n The size of the matrix.
    * @param row The row index of the value to get.
    * @param col The column index of the value to get.
    * @param value The value to get.
    *
    * @return 0 on success, -1 on error.
    */
int symmatrix_get(const PSOI_FLOAT *const matrix, size_t n, size_t row, size_t col, PSOI_FLOAT *const value);

/* Arithmetic Operations #####################################################*/

/*
    * @brief Add two symmetric matrices.
    *
    * @param matrix The matrix to add to.
    * @param other The matrix to add.
    * @param n The size of the matrices.
    *
    * @return 0 on success, -1 on error.
    */
int symmatrix_addassign(PSOI_FLOAT *const matrix, const PSOI_FLOAT *const other, size_t n);

/*
    * @brief Subtract two symmetric matrices.
    *
    * @param matrix The matrix to subtract from.
    * @param other The matrix to subtract.
    * @param n The size of the matrices.
    *
    * @return 0 on success, -1 on error.
    */
int symmatrix_subassign(PSOI_FLOAT *const matrix, const PSOI_FLOAT *const other, size_t n);

/*
    * @brief Multiply a symmetric matrix by a scalar.
    *
    * @param matrix The matrix to multiply.
    * @param n The size of the matrix.
    * @param scalar The scalar to multiply by.
    *
    * @return 0 on success, -1 on error.
    */
int symmatrix_mulassign(PSOI_FLOAT *const matrix, size_t n, PSOI_FLOAT scalar);

/* Memory Operations #########################################################*/

/*
    * @brief Copy a symmetric matrix.
    *
    * @param dst The destination matrix.
    * @param src The source matrix.
    * @param n The size of the matrices.
    *
    * @return 0 on success, -1 on error.
    */
int symmatrix_copy(PSOI_FLOAT *const dst, const PSOI_FLOAT *const src, size_t n);

/* 
    * @brief Copy row of a symmetric matrix.
    *
    * @param matrix The matrix.
    * @param n The size of the matrix.
    * @param idx The index of the row to copy.
    * @param row The row to copy.
    *
    * @return 0 on success, -1 on error.
    */
int symmatrix_get_row(const PSOI_FLOAT *const matrix, size_t n, size_t idx, PSOI_FLOAT *const row);

/* 
    * @brief Fill a symmetric matrix with a value.
    *
    * @param matrix The matrix.
    * @param n The size of the matrix.
    * @param value The value to fill the matrix with.
    *
    * @return 0 on success, -1 on error.
    */
int symmatrix_fill(PSOI_FLOAT *const matrix, size_t n, PSOI_FLOAT value);

#endif // __PSOI_SYMMATRIX_H__
