#pragma once
#include "wamatrix_basic.hpp"

namespace wamatrix::elementwise {

template <uint16_t DSTR, uint16_t DSTC>
void SubScalar(matrix_t dst, matrix_t srcA, data_t srcB) {
    /* Adjust Dst Size */
    dst.adjust_size(srcA.row(), srcA.col());
    /* Subtract Scalar */
    foreach (i, DSTR, dst.row()) {
        foreach (j, DSTC, dst.col()) {
            data_t tmp = srcA.get(i, j) - srcB;
            dst.set(i, j, tmp);
        }
    }
}

template <uint16_t DSTR, uint16_t DSTC>
void SubRowVec(matrix_t dst, matrix_t srcA, matrix_t srcB) {
    /* Adjust Dst Size */
    dst.adjust_size(srcA.row(), srcA.col());
    /* Subtract Row Vector */
    foreach (i, DSTR, dst.row()) {
        foreach (j, DSTC, dst.col()) {
            data_t tmp = srcA.get(i, j) - srcB.get(0, j);
            dst.set(i, j, tmp);
        }
    }
}

template <uint16_t DSTR, uint16_t DSTC>
void SubColVec(matrix_t dst, matrix_t srcA, matrix_t srcB) {
    /* Adjust Dst Size */
    dst.adjust_size(srcA.row(), srcA.col());
    /* Subtract Column Vector */
    foreach (i, DSTR, dst.row()) {
        foreach (j, DSTC, dst.col()) {
            data_t tmp = srcA.get(i, j) - srcB.get(i, 0);
            dst.set(i, j, tmp);
        }
    }
}

template <uint16_t DSTR, uint16_t DSTC>
void SubMatrix(matrix_t dst, matrix_t srcA, matrix_t srcB) {
    /* Adjust Dst Size */
    dst.adjust_size(srcA.row(), srcA.col());
    /* Subtract Matrix */
    foreach (i, DSTR, dst.row()) {
        foreach (j, DSTC, dst.col()) {
            data_t tmp = srcA.get(i, j) - srcB.get(i, j);
            dst.set(i, j, tmp);
        }
    }
}
}  // namespace wamatrix::elementwise
