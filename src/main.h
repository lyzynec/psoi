#ifndef __PSOI_H__
#define __PSOI_H__

#include <stddef.h>
#include "linalg/linalg.h"

/**
    * @brief The PSOI workspace containing the problem data and memory.
    */ 
typedef struct {
    size_t n; // dimension of the problem

    const PSOI_FLOAT *const H; // symmetric matrix H
    const PSOI_FLOAT *const h; // vector h
    const PSOI_FLOAT *const z_upper; // upper boundary vector
    const PSOI_FLOAT *const z_lower; // lower boundary vector

    PSOI_FLOAT *const z; // the current solution vector

    PSOI_FLOAT *const v0; // buffer vector 0
    PSOI_FLOAT *const v1; // buffer vector 1 
} psoi_workspace_t;

#endif // __PSOI_H__
