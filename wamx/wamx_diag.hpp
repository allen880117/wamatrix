#pragma once

#ifndef _WAMX_DIAG_HPP_
#define _WAMX_DIAG_HPP_

#include "wamx_basic.hpp"
#include "wamx_set.hpp"

namespace wamx {

template <uint32_t DS, uint32_t SS, uint16_t R>
/*
 * Diagonal Scatter, Column Vector to Matrix
 */
void DiagScatter(Matrix<DS> &dst, Matrix<SS> &src) {
    /* Adjust Dst Size */
    dst.adjust_size(src.row, src.row);
    /* Set Value to all zeros */
    SetScalars<DS, R, R>(dst, 0.0f);
    /* Diagonal Scatter */
    foreach (i, R, src.row) { dst.set(i, i, src.get(i, 0)); }
}

template <uint32_t DS, uint32_t SS, uint16_t R>
/*
 * Diagonal Gather, Matrix to Column Vector
 */
void DiagGather(Matrix<DS> &dst, Matrix<SS> &src) {
    /* Adjust Dst Size */
    dst.adjust_size(src.row, 1);

    /* Diag Gather */
    foreach (i, R, src.row) { dst.set(i, 0, src.get(i, i)); }
}

}  // namespace wamx

#endif