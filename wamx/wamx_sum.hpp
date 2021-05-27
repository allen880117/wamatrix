#pragma once

#ifndef _WAMX_SUM_HPP_
#define _WAMX_SUM_HPP_

#include "wamx_basic.hpp"

namespace wamx {

template <uint32_t DS, uint32_t SS, uint16_t DSTR, uint16_t DSTC>
/* Return Column Vector */
void SumOfRows(Matrix<DS> &dst, Matrix<SS> &src) {
    /* Adjust Dst Size */
    dst.adjust_size(src.row, 1);
    /* Do Summation */
    foreach (i, DSTR, src.row) {
        data_t sum = 0.0f;
        foreach (j, DSTC, src.col) { sum += src.get(i, j); }
        dst.set(i, 0, sum);
    }
}

template <uint32_t DS, uint32_t SS, uint16_t DSTR, uint16_t DSTC>
/* Return Row Vector */
void SumOfCols(Matrix<DS> &dst, Matrix<SS> &src) {
    /* Adjust Dst Size */
    dst.adjust_size(1, src.col);
    /* Do Summation */
    foreach (i, DSTC, src.col) {
        data_t sum = 0.0f;
        foreach (j, DSTR, src.row) { sum += src.get(j, i); }
        dst.set(0, i, sum);
    }
}
}  // namespace wamx

#endif