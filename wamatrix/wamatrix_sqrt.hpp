#include "wamatrix_basic.hpp"

namespace wamatrix {
namespace elementwise {

template <uint16_t DSTR, uint16_t DSTC>
void SqrtLocal(matrix_t src) {
    /* Square Root */
    foreach (i, DSTR, src.row()) {
        foreach (j, DSTC, src.col()) {
            data_t tmp = sqrt(src.get(i, j));
            src.set(i, j, tmp);
        }
    }
}

template <uint16_t DSTR, uint16_t DSTC>
void Sqrt(matrix_t dst, matrix_t src) {
    /* Adjust Dst Size */
    dst.adjust_size(src.row(), src.col());
    /* Square Root */
    foreach (i, DSTR, src.row()) {
        foreach (j, DSTC, src.col()) {
            data_t tmp = sqrt(src.get(i, j));
            dst.set(i, j, tmp);
        }
    }
}

}  // namespace elementwise
}  // namespace wamatrix
