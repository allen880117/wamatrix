#pragma once

#ifndef _WAMX_SORT_HPP_
#define _WAMX_SORT_HPP_

#include "wamx_basic.hpp"

namespace wamx {

template <uint32_t DS, uint32_t SS, uint16_t N>
void SortColVec(Matrix<DS> &dst, Matrix<SS> &src, const uint16_t channel_size) {
    /* Adjust Dst Size */
    dst.adjust_size(channel_size, 1);
    /* Initial Loop */
    foreach (i, N, channel_size) {
#pragma HLS unroll
        dst.set(i, 0, src.get(i, 0));
    }
    /* Sort Loop */
    foreach (i, N, channel_size - 1) {
        foreach (j, N, channel_size - 1 - i) {
            data_t dst_j_0 = dst.get(j + 0, 0);
            data_t dst_j_1 = dst.get(j + 1, 0);
            if (dst_j_0 > dst_j_1) {
                dst.set(j + 0, 0, dst_j_1);
                dst.set(j + 1, 0, dst_j_0);
            }
        }
    }
}

template <uint32_t DS, uint32_t SS, uint16_t N>
void SortColVecWOrder(Matrix<DS> &dst, uint16_t order[N],
                      Matrix<SS> &src, const uint16_t channel_size) {
    /* Adjust Dst Size */
    dst.adjust_size(channel_size, 1);
    /* Initial Loop */
    foreach (i, N, channel_size) {
#pragma HLS unroll
        dst.set(i, 0, src.get(i, 0));
        order[i] = i;
    }
    /* Sort Loop */
    foreach (i, N, channel_size - 1) {
        foreach (j, N, channel_size - 1 - i) {
            data_t   dst_j_0   = dst.get(j + 0, 0);
            data_t   dst_j_1   = dst.get(j + 1, 0);
            uint16_t order_j_0 = order[j + 0];
            uint16_t order_j_1 = order[j + 1];
            if (dst_j_0 > dst_j_1) {
                dst.set(j + 0, 0, dst_j_1);
                dst.set(j + 1, 0, dst_j_0);
                order[j]     = order_j_1;
                order[j + 1] = order_j_0;
            }
        }
    }
}

template <uint32_t DS, uint32_t SS, uint16_t SRC_R, uint16_t SRC_C>
void ReorderCol(Matrix<DS> &dst, Matrix<SS> &src, const uint16_t order[SRC_C]) {
    /* Make Sure You Run Sort First */
    /* Adjust Dst Size */
    dst.adjust_size(src.row, src.col);
    /* Reorder Columns */
    foreach (i, SRC_R, src.row) {
        foreach (j, SRC_C, src.col) {
#pragma HLS unroll
            dst.set(i, j, src.get(i, order[j]));
        }
    }
}

template <uint32_t DS, uint32_t SS, uint16_t SRC_R, uint16_t SRC_C>
void ReorderRow(Matrix<DS> &dst, Matrix<SS> &src, const uint16_t order[SRC_R]) {
    /* Make Sure You Run Sort First */
    /* Adjust Dst Size */
    dst.adjust_size(src.row, src.col);
    /* Reorder Columns */
    foreach (i, SRC_R, src.row) {
        foreach (j, SRC_C, src.col) {
#pragma HLS unroll
            dst.set(i, j, src.get(order[i], j));
        }
    }
}

}  // namespace wamx

#endif