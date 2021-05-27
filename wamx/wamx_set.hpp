#pragma once

#ifndef _WAMX_SET_HPP_
#define _WAMX_SET_HPP_

#include "wamx_basic.hpp"

namespace wamx {

template <uint32_t DS, uint16_t DSTR, uint16_t DSTC>
/* This Function Won't Adjust the Size of Dst */
void SetScalars(Matrix<DS> &dst, const data_t scalar) {
    /* Given Scalar */
    foreach (i, DSTR, dst.row) {
        foreach (j, DSTC, dst.col) { dst.set(i, j, scalar); }
    }
}

template <uint32_t DS, uint16_t DSTR, uint16_t DSTC>
/* This Function Won't Adjust the Size of Dst */
void SetEye(Matrix<DS> &dst, const data_t scalar) {
    /* Given Scalar in Diagonal */
    foreach (i, DSTR, dst.row) {
        foreach (j, DSTC, dst.col) {
            data_t tmp = (i == j) ? (scalar) : (0);
            dst.set(i, j, tmp);
        }
    }
}

}  // namespace wamx

#endif