#include "wamatrix_basic.hpp"

namespace wamatrix {

template <uint16_t SRCR, uint16_t SRCC>
void Transpose(matrix_t dst, matrix_t src) {
    /* Adjust Dst Size */
    dst.adjust_size(src.col(), src.row());
    /* Transpose */
    foreach (i, SRCR, src.row()) {
        foreach (j, SRCC, src.col()) {
            data_t tmp = src.get(i, j);
            dst.set(j, i, tmp);
        }
    }
}

}  // namespace wamatrix
