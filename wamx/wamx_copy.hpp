#pragma once

#ifndef _WAMX_COPY_HPP_
#define _WAMX_COPY_HPP_

#include "wamx_basic.hpp"

namespace wamx {

template <uint32_t DS, uint32_t SS, uint16_t SRCR, uint16_t SRCC>
void CopyMatrix(Matrix<DS> &dst, Matrix<SS> &src) {
    /* Adjust Dst Size */
    dst.adjust_size(src.row, src.col);
    /* Copy */
    foreach (i, SRCR, src.row) {
        foreach (j, SRCC, src.col) {
            data_t tmp = src.get(i, j);
            dst.set(i, j, tmp);
        }
    }
}

}  // namespace wamx

#endif