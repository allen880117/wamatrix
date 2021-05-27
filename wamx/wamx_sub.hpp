#pragma once

#ifndef _WAMX_SUB_HPP_
#define _WAMX_SUB_HPP_

#include "wamx_basic.hpp"

namespace wamx {
namespace ew {
template <uint32_t DS, uint32_t SSA, uint16_t DSTR, uint16_t DSTC>
void SubScalar(Matrix<DS> &dst, Matrix<SSA> &srcA, data_t srcB) {
    /* Adjust Dst Size */
    dst.adjust_size(srcA.row, srcA.col);
    /* Subtract Scalar */
    foreach (i, DSTR, dst.row) {
        foreach (j, DSTC, dst.col) {
            data_t tmp = srcA.get(i, j) - srcB;
            dst.set(i, j, tmp);
        }
    }
}

template <uint32_t DS, uint32_t SSA, uint32_t SSB, uint16_t DSTR, uint16_t DSTC>
void SubRowVec(Matrix<DS> &dst, Matrix<SSA> &srcA, Matrix<SSB> &srcB) {
    /* Adjust Dst Size */
    dst.adjust_size(srcA.row, srcA.col);
    /* Subtract Row Vector */
    foreach (i, DSTR, dst.row) {
        foreach (j, DSTC, dst.col) {
            data_t tmp = srcA.get(i, j) - srcB.get(0, j);
            dst.set(i, j, tmp);
        }
    }
}

template <uint32_t DS, uint32_t SSA, uint32_t SSB, uint16_t DSTR, uint16_t DSTC>
void SubColVec(Matrix<DS> &dst, Matrix<SSA> &srcA, Matrix<SSB> &srcB) {
    /* Adjust Dst Size */
    dst.adjust_size(srcA.row, srcA.col);
    /* Subtract Column Vector */
    foreach (i, DSTR, dst.row) {
        foreach (j, DSTC, dst.col) {
            data_t tmp = srcA.get(i, j) - srcB.get(i, 0);
            dst.set(i, j, tmp);
        }
    }
}

template <uint32_t DS, uint32_t SSA, uint32_t SSB, uint16_t DSTR, uint16_t DSTC>
void SubMatrix(Matrix<DS> &dst, Matrix<SSA> &srcA, Matrix<SSB> &srcB) {
    /* Adjust Dst Size */
    dst.adjust_size(srcA.row, srcA.col);
    /* Subtract Matrix */
    foreach (i, DSTR, dst.row) {
        foreach (j, DSTC, dst.col) {
            data_t tmp = srcA.get(i, j) - srcB.get(i, j);
            dst.set(i, j, tmp);
        }
    }
}
}  // namespace ew
}  // namespace wamx

#endif