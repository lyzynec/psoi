#include "symmatrix.h"
#include <string.h>


int symmatrix_set(PSOI_FLOAT *const matrix, size_t n, size_t row, size_t col, PSOI_FLOAT value) {

    if (row >= n || col >= n) {
        return -1;
    }

    matrix[SYMMATRIX_INDEX(n, row, col)] = value;

    return 0;
}

int symmatrix_get(const PSOI_FLOAT *const matrix, size_t n, size_t row, size_t col, PSOI_FLOAT *const value) {
    if (row >= n || col >= n) {
        return -1;
    }

    size_t i = row < col ? row : col;
    size_t j = row < col ? col : row;

    *value = matrix[SYMMATRIX_INDEX(n, row, col)];
    return 0;
}

int symmatrix_addassign(PSOI_FLOAT *const matrix, const PSOI_FLOAT *const other, size_t n) {
    for (size_t i = 0; i < SYMMATRIX_DATALEN(n); i++) {
        matrix[i] += other[i];
    }

    return 0;
}

int symmatrix_subassign(PSOI_FLOAT *const matrix, const PSOI_FLOAT *const other, size_t n) {
    for (size_t i = 0; i < SYMMATRIX_DATALEN(n); i++) {
        matrix[i] -= other[i];
    }

    return 0;
}

int symmatrix_mulassign(PSOI_FLOAT *const matrix, size_t n, PSOI_FLOAT scalar) {
    for (size_t i = 0; i < SYMMATRIX_DATALEN(n); i++) {
        matrix[i] *= scalar;
    }

    return 0;
}

int symmatrix_copy(PSOI_FLOAT *const dst, const PSOI_FLOAT *const src, size_t n) {
    for (size_t i = 0; i < SYMMATRIX_DATALEN(n); i++) {
        dst[i] = src[i];
    }

    return 0;
}

int symmatrix_get_row(const PSOI_FLOAT *const matrix, size_t n, size_t idx, PSOI_FLOAT *const row) {
    if (idx >= n) {
        return -1;
    }

    // vertical copy
    for (size_t r = 0; r < idx; r++) {
        row[r] = matrix[SYMMATRIX_INDEX(n, r, idx)];
    }

    // horizontal copy
    memcpy(&row[idx], &matrix[SYMMATRIX_INDEX(n, idx, idx)], idx);

    return 0;
}

int symmatrix_fill(PSOI_FLOAT *const matrix, size_t n, PSOI_FLOAT value) {
    memset(matrix, value, SYMMATRIX_DATALEN(n) * sizeof(PSOI_FLOAT));

    return 0;
}
