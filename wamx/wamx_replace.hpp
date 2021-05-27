#pragma once

#ifndef _WAMX_REPLACE_HPP_
#define _WAMX_REPLACE_HPP_

#include "wamx_basic.hpp"

namespace wamx {

template <uint32_t DS, uint32_t SS, uint16_t DST_R, uint16_t SRC_C>
void ReplaceCols(Matrix<DS> &dst, Matrix<SS> &src, const uint16_t start_col) {
    /* Replace */
    foreach (i, DST_R, dst.row) {
        foreach (j, SRC_C, src.col) {
            dst.set(i, j + start_col, src.get(i, j));
        }
    }
}

}  // namespace wamx

#endif