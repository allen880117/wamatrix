#pragma once

#ifndef _WAMX_ABS_HPP_
#define _WAMX_ABS_HPP_

#include "wamx_basic.hpp"

namespace wamx {

template <uint32_t DS, uint32_t SS, uint16_t SRCR, uint16_t SRCC>
void AbsMatrix(Matrix<DS> &dst, Matrix<SS> &src) {
    /* Adjust Dst Size */
    dst.adjust_size(src.row, src.col);
    /* Abs */
    foreach (i, SRCR, src.row) {
        foreach (j, SRCC, src.col) {
            data_t tmp = fabs(src.get(i, j));
            dst.set(i, j, tmp);
        }
    }
}

template <uint32_t SS, uint16_t SRCR, uint16_t SRCC>
void AbsMatrixLocal(Matrix<SS> &src) {
    /* Abs */
    foreach (i, SRCR, src.row) {
        foreach (j, SRCC, src.col) {
            data_t tmp = fabs(src.get(i, j));
            src.set(i, j, tmp);
        }
    }
}

}  // namespace wamx

#endif