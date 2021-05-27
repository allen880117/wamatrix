#pragma once

#ifndef _WAMX_TRANSPOSE_HPP_
#define _WAMX_TRANSPOSE_HPP_

#include "wamx_basic.hpp"

namespace wamx {

template <uint32_t DS, uint32_t SS, uint16_t SRCR, uint16_t SRCC>
void Transpose(Matrix<DS> &dst, Matrix<SS> &src) {
    /* Adjust Dst Size */
    dst.adjust_size(src.col, src.row);
    /* Transpose */
    foreach (i, SRCR, src.row) {
        foreach (j, SRCC, src.col) {
            data_t tmp = src.get(i, j);
            dst.set(j, i, tmp);
        }
    }
}

}  // namespace wamx

#endif