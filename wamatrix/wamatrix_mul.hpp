#pragma once
#include "wamatrix_basic.hpp"

namespace wamatrix::elementwise {

template <uint16_t DSTR, uint16_t DSTC>
void MulScalar(matrix_t dst, matrix_t srcA, data_t srcB) {
    /* Adjust Dst Size */
    dst.adjust_size(srcA.row(), srcA.col());
    /* Multiply Scalar */
    foreach (i, DSTR, dst.row()) {
        foreach (j, DSTC, dst.col()) {
            data_t tmp = srcA.get(i, j) * srcB;
            dst.set(i, j, tmp);
        }
    }
}

template <uint16_t DSTR, uint16_t DSTC>
void MulRowVec(matrix_t dst, matrix_t srcA, matrix_t srcB) {
    /* Adjust Dst Size */
    dst.adjust_size(srcA.row(), srcA.col());
    /* Multiply Row Vector */
    foreach (i, DSTR, dst.row()) {
        foreach (j, DSTC, dst.col()) {
            data_t tmp = srcA.get(i, j) * srcB.get(0, j);
            dst.set(i, j, tmp);
        }
    }
}

template <uint16_t DSTR, uint16_t DSTC>
void MulColVec(matrix_t dst, matrix_t srcA, matrix_t srcB) {
    /* Adjust Dst Size */
    dst.adjust_size(srcA.row(), srcA.col());
    /* Multiply Column Vector */
    foreach (i, DSTR, dst.row()) {
        foreach (j, DSTC, dst.col()) {
            data_t tmp = srcA.get(i, j) * srcB.get(i, 0);
            dst.set(i, j, tmp);
        }
    }
}

template <uint16_t DSTR, uint16_t DSTC>
void MulMatrix(matrix_t dst, matrix_t srcA, matrix_t srcB) {
    /* Adjust Dst Size */
    dst.adjust_size(srcA.row(), srcA.col());
    /* Multiply Matrix */
    foreach (i, DSTR, dst.row()) {
        foreach (j, DSTC, dst.col()) {
            data_t tmp = srcA.get(i, j) * srcB.get(i, j);
            dst.set(i, j, tmp);
        }
    }
}

}  // namespace wamatrix::elementwise

namespace wamatrix {
template <uint16_t DSTR, uint16_t INNERK, uint16_t DSTC>
/* Matrix Multiplication ( A * B ) */
void MulMatrixFF(matrix_t dst, matrix_t srcA, matrix_t srcB) {
    /* Adjust Dst Size First */
    dst.adjust_size(srcA.row(), srcB.col());

    /* Do Multiplication A*B */
    foreach (i, DSTR, dst.row()) {
        foreach (j, DSTC, dst.col()) {
            data_t sum = 0.0f;
            foreach_pipeline(k, INNERK, srcA.col()) {
                sum += srcA.get(i, k) * srcB.get(k, j);
            }
            dst.set(i, j, sum);
        }
    }
}

template <uint16_t DSTR, uint16_t INNERK, uint16_t DSTC>
/* Matrix Multiplication ( A * B' ) */
void MulMatrixFT(matrix_t dst, matrix_t srcA, matrix_t srcB) {
    /* Adjust Dst Size First */
    dst.adjust_size(srcA.row(), srcB.row());

    /* Do Multiplication A*B */
    foreach (i, DSTR, dst.row()) {
        foreach (j, DSTC, dst.col()) {
            data_t sum = 0.0f;
            foreach_pipeline(k, INNERK, srcA.col()) {
                sum += srcA.get(i, k) * srcB.get(j, k);
            }
            dst.set(i, j, sum);
        }
    }
}

template <uint16_t DSTR, uint16_t INNERK, uint16_t DSTC>
/* Matrix Multiplication ( A' * B ) */
void MulMatrixTF(matrix_t dst, matrix_t srcA, matrix_t srcB) {
    /* Adjust Dst Size First */
    dst.adjust_size(srcA.col(), srcB.col());

    /* Do Multiplication A*B */
    foreach (i, DSTR, dst.row()) {
        foreach (j, DSTC, dst.col()) {
            data_t sum = 0.0f;
            foreach_pipeline(k, INNERK, srcA.row()) {
                sum += srcA.get(k, i) * srcB.get(k, j);
            }
            dst.set(i, j, sum);
        }
    }
}

}  // namespace wamatrix
