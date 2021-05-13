#include "wamatrix_basic.hpp"

namespace wamatrix {

template <uint16_t SRCR, uint16_t SRCC>
void AbsMatrix(matrix_t dst, matrix_t src) {
    /* Adjust Dst Size */
    dst.adjust_size(src.row(), src.col());
    /* Abs */
    foreach (i, SRCR, src.row()) {
        foreach (j, SRCC, src.col()) {
            data_t tmp = abs(src.get(i, j));
            dst.set(i, j, tmp);
        }
    }
}

template <uint16_t SRCR, uint16_t SRCC>
void AbsMatrixLocal(matrix_t src) {
    /* Abs */
    foreach (i, SRCR, src.row()) {
        foreach (j, SRCC, src.col()) {
            data_t tmp = abs(src.get(i, j));
            src.set(i, j, tmp);
        }
    }
}

}  // namespace wamatrix
