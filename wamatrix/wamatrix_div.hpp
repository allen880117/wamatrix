#pragma once
#include "wamatrix_basic.hpp"

namespace wamatrix::elementwise {

template <uint16_t DSTR, uint16_t DSTC>
void DivScalar(matrix_t dst, matrix_t srcA, data_t srcB) {
    /* Adjust Dst Size */
    dst.adjust_size(srcA.row(), srcA.col());
    /* Divide Scalar */
    foreach (i, DSTR, dst.row()) {
        foreach (j, DSTC, dst.col()) {
            data_t tmp = srcA.get(i, j) / srcB;
            dst.set(i, j, tmp);
        }
    }
}

template <uint16_t DSTR, uint16_t DSTC>
void DivRowVec(matrix_t dst, matrix_t srcA, matrix_t srcB) {
    /* Adjust Dst Size */
    dst.adjust_size(srcA.row(), srcA.col());
    /* Divide Row Vector */
    foreach (i, DSTR, dst.row()) {
        foreach (j, DSTC, dst.col()) {
            data_t tmp = srcA.get(i, j) / srcB.get(0, j);
            dst.set(i, j, tmp);
        }
    }
}

template <uint16_t DSTR, uint16_t DSTC>
void DivColVec(matrix_t dst, matrix_t srcA, matrix_t srcB) {
    /* Adjust Dst Size */
    dst.adjust_size(srcA.row(), srcA.col());
    /* Divide Column Vector */
    foreach (i, DSTR, dst.row()) {
        foreach (j, DSTC, dst.col()) {
            data_t tmp = srcA.get(i, j) / srcB.get(i, 0);
            dst.set(i, j, tmp);
        }
    }
}

template <uint16_t DSTR, uint16_t DSTC>
void DivMatrix(matrix_t dst, matrix_t srcA, matrix_t srcB) {
    /* Adjust Dst Size */
    dst.adjust_size(srcA.row(), srcA.col());
    /* Divide Matrix */
    foreach (i, DSTR, dst.row()) {
        foreach (j, DSTC, dst.col()) {
            data_t tmp = srcA.get(i, j) / srcB.get(i, j);
            dst.set(i, j, tmp);
        }
    }
}

}  // namespace wamatrix::elementwise
