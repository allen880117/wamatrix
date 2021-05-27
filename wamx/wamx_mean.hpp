#pragma once

#ifndef _WAMX_MEAN_HPP_
#define _WAMX_MEAN_HPP_

#include "wamx_basic.hpp"
#include "wamx_sum.hpp"

namespace wamx {

template <uint32_t DS, uint32_t SS, uint16_t DSTR, uint16_t DSTC>
/* Return Column Vector */
void MeanOfRows(Matrix<DS> &dst, Matrix<SS> &src) {
    /* Do Summation (Size of Dst will be adjusted here )*/
    SumOfRows<DS, SS, DSTR, DSTC>(dst, src);
    /* Divide */
    data_t divider = src.col;
    foreach (i, DSTR, dst.row) {
        data_t tmp = dst.get(i, 0) / divider;
        dst.set(i, 0, tmp);
    }
}

template <uint32_t DS, uint32_t SS, uint16_t DSTR, uint16_t DSTC>
/* Return Row Vector */
void MeanOfCols(Matrix<DS> &dst, Matrix<SS> &src) {
    /* Do Summation (Size of Dst will be adjusted here )*/
    SumOfCols<DS, SS, DSTR, DSTC>(dst, src);
    /* Divide */
    data_t divider = src.row;
    foreach (i, DSTC, dst.col) {
        data_t tmp = dst.get(0, i) / divider;
        dst.set(0, i, tmp);
    }
}

}  // namespace wamx

#endif