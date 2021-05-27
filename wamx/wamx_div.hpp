#pragma once

#ifndef _WAMX_DIV_HPP_
#define _WAMX_DIV_HPP_

#include "wamx_basic.hpp"

namespace wamx {
namespace ew {

template <uint32_t DS, uint32_t SSA, uint16_t DSTR, uint16_t DSTC>
void DivScalar(Matrix<DS> &dst, Matrix<SSA> &srcA, const data_t srcB) {
    /* Adjust Dst Size */
    dst.adjust_size(srcA.row, srcA.col);
    /* Divide Scalar */
    foreach (i, DSTR, dst.row) {
        foreach (j, DSTC, dst.col) {
            data_t tmp = srcA.get(i, j) / srcB;
            dst.set(i, j, tmp);
        }
    }
}

template <uint32_t DS, uint32_t SSA, uint32_t SSB, uint16_t DSTR, uint16_t DSTC>
void DivRowVec(Matrix<DS> &dst, Matrix<SSA> &srcA, Matrix<SSB> &srcB) {
    /* Adjust Dst Size */
    dst.adjust_size(srcA.row, srcA.col);
    /* Divide Row Vector */
    foreach (i, DSTR, dst.row) {
        foreach (j, DSTC, dst.col) {
            data_t tmp = srcA.get(i, j) / srcB.get(0, j);
            dst.set(i, j, tmp);
        }
    }
}

template <uint32_t DS, uint32_t SSA, uint32_t SSB, uint16_t DSTR, uint16_t DSTC>
void DivColVec(Matrix<DS> &dst, Matrix<SSA> &srcA, Matrix<SSB> &srcB) {
    /* Adjust Dst Size */
    dst.adjust_size(srcA.row, srcA.col);
    /* Divide Column Vector */
    foreach (i, DSTR, dst.row) {
        foreach (j, DSTC, dst.col) {
            data_t tmp = srcA.get(i, j) / srcB.get(i, 0);
            dst.set(i, j, tmp);
        }
    }
}

template <uint32_t DS, uint32_t SSA, uint32_t SSB, uint16_t DSTR, uint16_t DSTC>
void DivMatrix(Matrix<DS> &dst, Matrix<SSA> &srcA, Matrix<SSB> &srcB) {
    /* Adjust Dst Size */
    dst.adjust_size(srcA.row, srcA.col);
    /* Divide Matrix */
    foreach (i, DSTR, dst.row) {
        foreach (j, DSTC, dst.col) {
            data_t tmp = srcA.get(i, j) / srcB.get(i, j);
            dst.set(i, j, tmp);
        }
    }
}
}  // namespace ew
}  // namespace wamx

#endif