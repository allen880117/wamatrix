#pragma once

#ifndef _WAMX_SLICE_HPP_
#define _WAMX_SLICE_HPP_

#include "wamx_basic.hpp"

namespace wamx {

template <uint32_t DS, uint32_t SS, uint16_t SLICE_R_SIZE,
          uint16_t SLICE_C_SIZE>
void SliceMatrix(Matrix<DS> &dst, Matrix<SS> &src, const uint16_t src_row_start,
                 const uint16_t src_row_size, const uint16_t src_col_start,
                 const uint16_t src_col_size) {
    /* Adjust Dst Size */
    dst.adjust_size(src_row_size, src_col_size);
    /* Slice */
    foreach (i, SLICE_R_SIZE, src_row_size) {
        foreach (j, SLICE_C_SIZE, src_col_size) {
            data_t tmp = src.get(src_row_start + i, src_col_start + j);
            dst.set(i, j, tmp);
        }
    }
}

}  // namespace wamx

#endif