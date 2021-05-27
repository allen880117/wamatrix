#pragma once

#ifndef _WAMX_APPEND_HPP_
#define _WAMX_APPEND_HPP_

#include "wamx_basic.hpp"

namespace wamx {

template <uint32_t DS, uint32_t SSA, uint32_t SSB, uint16_t SRC_A_R,
          uint16_t SRC_A_C, uint16_t SRC_B_R, uint16_t SRC_B_C>
void AppendMoreRow(Matrix<DS> &dst, Matrix<SSA> &src_A, Matrix<SSB> &src_B) {
    /* Adjust Dst Size First */
    dst.adjust_size(src_A.row + src_B.row, src_A.col);
    /* Append */
    /* Move A into Dst First */
    foreach (i, SRC_A_R, src_A.row)
        foreach (j, SRC_A_C, src_A.col)
            dst.set(i, j, src_A.get(i, j));
    /* Move B into Dst */
    foreach (i, SRC_B_R, src_B.row)
        foreach (j, SRC_B_C, src_B.col)
            dst.set(src_A.row + i, j, src_B.get(i, j));
}

template <uint32_t DS, uint32_t SSA, uint32_t SSB, uint16_t SRC_A_R,
          uint16_t SRC_A_C, uint16_t SRC_B_R, uint16_t SRC_B_C>
void AppendMoreCol(Matrix<DS> &dst, Matrix<SSA> &src_A, Matrix<SSB> &src_B) {
    /* Adjust Dst Size First */
    dst.adjust_size(src_A.row, src_A.col + src_B.col);
    /* Append */
    /* Move A into Dst First */
    foreach (i, SRC_A_R, src_A.row)
        foreach (j, SRC_A_C, src_A.col)
            dst.set(i, j, src_A.get(i, j));
    /* Move B into Dst */
    foreach (i, SRC_B_R, src_B.row)
        foreach (j, SRC_B_C, src_B.col)
            dst.set(i, src_A.col + j, src_B.get(i, j));
}

}  // namespace wamx

#endif