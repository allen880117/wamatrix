#pragma once

#ifndef _WAMX_MUL_HPP_
#define _WAMX_MUL_HPP_

#include "wamx_basic.hpp"

namespace wamx {
namespace ew {

template <uint32_t DS, uint32_t SSA, uint16_t DSTR, uint16_t DSTC>
void MulScalar(Matrix<DS> &dst, Matrix<SSA> &srcA, const data_t srcB) {
    /* Adjust Dst Size */
    dst.adjust_size(srcA.row, srcA.col);
    /* Multiply Scalar */
    foreach (i, DSTR, dst.row) {
        foreach (j, DSTC, dst.col) {
            data_t tmp = srcA.get(i, j) * srcB;
            dst.set(i, j, tmp);
        }
    }
}

template <uint32_t DS, uint32_t SSA, uint32_t SSB, uint16_t DSTR, uint16_t DSTC>
void MulRowVec(Matrix<DS> &dst, Matrix<SSA> &srcA, Matrix<SSB> &srcB) {
    /* Adjust Dst Size */
    dst.adjust_size(srcA.row, srcA.col);
    /* Multiply Row Vector */
    foreach (i, DSTR, dst.row) {
        foreach (j, DSTC, dst.col) {
            data_t tmp = srcA.get(i, j) * srcB.get(0, j);
            dst.set(i, j, tmp);
        }
    }
}

template <uint32_t DS, uint32_t SSA, uint32_t SSB, uint16_t DSTR, uint16_t DSTC>
void MulColVec(Matrix<DS> &dst, Matrix<SSA> &srcA, Matrix<SSB> &srcB) {
    /* Adjust Dst Size */
    dst.adjust_size(srcA.row, srcA.col);
    /* Multiply Column Vector */
    foreach (i, DSTR, dst.row) {
        foreach (j, DSTC, dst.col) {
            data_t tmp = srcA.get(i, j) * srcB.get(i, 0);
            dst.set(i, j, tmp);
        }
    }
}

template <uint32_t DS, uint32_t SSA, uint32_t SSB, uint16_t DSTR, uint16_t DSTC>
void MulMatrix(Matrix<DS> &dst, Matrix<SSA> &srcA, Matrix<SSB> &srcB) {
    /* Adjust Dst Size */
    dst.adjust_size(srcA.row, srcA.col);
    /* Multiply Matrix */
    foreach (i, DSTR, dst.row) {
        foreach (j, DSTC, dst.col) {
            data_t tmp = srcA.get(i, j) * srcB.get(i, j);
            dst.set(i, j, tmp);
        }
    }
}
}  // namespace ew
}  // namespace wamx

namespace wamx {
template <uint32_t DS, uint32_t SSA, uint32_t SSB, uint16_t DSTR,
          uint16_t INNERK, uint16_t DSTC>
/* Matrix Multiplication ( A * B ) */
void MulMatrixFF(Matrix<DS> &dst, Matrix<SSA> &srcA, Matrix<SSB> &srcB) {
    /* Adjust Dst Size First */
    dst.adjust_size(srcA.row, srcB.col);

    /* Do Multiplication A*B */
    foreach (i, DSTR, dst.row) {
        foreach (j, DSTC, dst.col) {
            data_t sum = 0.0f;
            foreach_pipeline(k, INNERK, srcA.col) {
                sum += srcA.get(i, k) * srcB.get(k, j);
            }
            dst.set(i, j, sum);
        }
    }
}

template <uint32_t DS, uint32_t SSA, uint32_t SSB, uint16_t DSTR,
          uint16_t INNERK, uint16_t DSTC>
/* Matrix Multiplication ( A * B' ) */
void MulMatrixFT(Matrix<DS> &dst, Matrix<SSA> &srcA, Matrix<SSB> &srcB) {
    /* Adjust Dst Size First */
    dst.adjust_size(srcA.row, srcB.row);

    /* Do Multiplication A*B */
    foreach (i, DSTR, dst.row) {
        foreach (j, DSTC, dst.col) {
            data_t sum = 0.0f;
            foreach_pipeline(k, INNERK, srcA.col) {
                sum += srcA.get(i, k) * srcB.get(j, k);
            }
            dst.set(i, j, sum);
        }
    }
}

template <uint32_t DS, uint32_t SSA, uint32_t SSB, uint16_t DSTR,
          uint16_t INNERK, uint16_t DSTC>
/* Matrix Multiplication ( A' * B ) */
void MulMatrixTF(Matrix<DS> &dst, Matrix<SSA> &srcA, Matrix<SSB> &srcB) {
    /* Adjust Dst Size First */
    dst.adjust_size(srcA.col, srcB.col);

    /* Do Multiplication A*B */
    foreach (i, DSTR, dst.row) {
        foreach (j, DSTC, dst.col) {
            data_t sum = 0.0f;
            foreach_pipeline(k, INNERK, srcA.row) {
                sum += srcA.get(k, i) * srcB.get(k, j);
            }
            dst.set(i, j, sum);
        }
    }
}

}  // namespace wamx

#endif