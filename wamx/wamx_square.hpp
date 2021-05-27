#pragma once

#ifndef _WAMX_SQUARE_HPP_
#define _WAMX_SQUARE_HPP_

#include "wamx_basic.hpp"

namespace wamx {
namespace ew {

template <uint32_t SS, uint16_t DSTR, uint16_t DSTC>
void SquareLocal(Matrix<SS> &src) {
    /* Square */
    foreach (i, DSTR, src.row) {
        foreach (j, DSTC, src.col) {
            data_t tmp = src.get(i, j);
            src.set(i, j, tmp * tmp);
        }
    }
}

template <uint32_t DS, uint32_t SS, uint16_t DSTR, uint16_t DSTC>
void Square(Matrix<DS> &dst, Matrix<SS> &src) {
    /* Adjust Dst Size */
    dst.adjust_size(src.row, src.col);
    /* Square */
    foreach (i, DSTR, src.row) {
        foreach (j, DSTC, src.col) {
            data_t tmp = src.get(i, j);
            dst.set(i, j, tmp * tmp);
        }
    }
}

}  // namespace ew
}  // namespace wamx

#endif