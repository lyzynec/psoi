#include "linalg.h"
#include "vector.h"

int mul_symmat_vec(
    const PSOI_FLOAT *const matrix,
    const PSOI_FLOAT *const vector,
    PSOI_FLOAT *const result,
    size_t n
) {
    vector_fill(result, n, 0);

    size_t r = 0;
    size_t w = 0;

    for (size_t i = 0; i < SYMMATRIX_DATALEN(n); i++) {
        const PSOI_FLOAT m = matrix[i];
        if (r + w == n) {
            w = 0;
            r++;
        } else {
            result[r] += m * vector[r + w];
        }

        result[r+w] += m * vector[r];

        w++;
    }

    return 0;
}

int mul_symmat_vec_at_row(
    const PSOI_FLOAT *const matrix,
    const PSOI_FLOAT *const vector,
    size_t n,
    size_t row,
    PSOI_FLOAT *const result
) {
    if (row >= n) {
        return -1;
    }

    PSOI_FLOAT res_loc = 0;

    // vertical mult
    for (size_t r = 0; r < row; r++){
        res_loc += matrix[r * n + row - (r * r - r) / 2 - r] * vector[r];
    }

    // horizontal mult
    size_t offset = row * n - (row * row - row) / 2;
    for (size_t c = 0; c < row; c++){
        res_loc += matrix[offset + c] * vector[c];
    }

    *result = res_loc;

    return 0;
}

int quad_mul_symmat_vec(
    const PSOI_FLOAT *const matrix,
    const PSOI_FLOAT *const vector,
    PSOI_FLOAT *const helper,
    size_t n,
    PSOI_FLOAT *const result
    
) {

    if (!mul_symmat_vec(matrix, vector, result, n)) {
        return -1;
    }

    if (!vector_dot(vector, helper, result, n)) {
        return -1;
    }

    return 0;
}
