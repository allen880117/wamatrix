#pragma once

#ifndef _WAMX_SQRT_HPP_
#define _WAMX_SQRT_HPP_

#include "wamx_basic.hpp"

namespace wamx {
namespace ew {

template <uint32_t SS, uint16_t DSTR, uint16_t DSTC>
void SqrtLocal(Matrix<SS> &src) {
    /* Square Root */
    foreach (i, DSTR, src.row) {
        foreach (j, DSTC, src.col) {
            data_t tmp = sqrt(src.get(i, j));
            src.set(i, j, tmp);
        }
    }
}

template <uint32_t DS, uint32_t SS, uint16_t DSTR, uint16_t DSTC>
void Sqrt(Matrix<DS> &dst, Matrix<SS> &src) {
    /* Adjust Dst Size */
    dst.adjust_size(src.row, src.col);
    /* Square Root */
    foreach (i, DSTR, src.row) {
        foreach (j, DSTC, src.col) {
            data_t tmp = sqrt(src.get(i, j));
            dst.set(i, j, tmp);
        }
    }
}

}  // namespace ew
}  // namespace wamx

#endif