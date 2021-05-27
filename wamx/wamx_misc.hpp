#pragma once

#ifndef _WAMX_MISC_HPP_
#define _WAMX_MISC_HPP_

#include "wamx_basic.hpp"

namespace wamx {

template <uint32_t SS, uint16_t R, uint16_t C>
void ClampFiniteValues(Matrix<SS> &src) {
    /* Clamp */
    foreach (i, R, src.row) {
        foreach (j, C, src.col) {
            if (!std::isfinite(src.get(i, j))) src.set(i, j, 0);
        }
    }
}

}  // namespace wamx

#endif