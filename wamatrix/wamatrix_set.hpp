#include "wamatrix_basic.hpp"

namespace wamatrix {

template <uint16_t DSTR, uint16_t DSTC>
/* This Function Won't Adjust the Size of Dst */
void SetScalars(matrix_t dst, data_t scalar) {
    /* Given Scalar */
    foreach (i, DSTR, dst.row()) {
        foreach (j, DSTC, dst.col()) { dst.set(i, j, scalar); }
    }
}

template <uint16_t DSTR, uint16_t DSTC>
/* This Function Won't Adjust the Size of Dst */
void SetEye(matrix_t dst, data_t scalar) {
    /* Given Scalar in Diagonal */
    foreach (i, DSTR, dst.row()) {
        foreach (j, DSTC, dst.col()) {
            data_t tmp = (i == j) ? (scalar) : (0);
            dst.set(i, j, tmp);
        }
    }
}

}  // namespace wamatrix
