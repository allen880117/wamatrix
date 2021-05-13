#include "wamatrix_basic.hpp"
#include "wamatrix_sum.hpp"

namespace wamatrix {

template <uint16_t DSTR, uint16_t DSTC>
/* Return Column Vector */
void MeanOfRow(matrix_t dst, matrix_t src) {
    /* Do Summation (Size of Dst will be adjusted here )*/
    SumOfRow<DSTR, DSTC>(dst, src);
    /* Divide */
    data_t divider = src.col();
    foreach (i, DSTR, dst.row()) {
        data_t tmp = dst.get(i, 0) / divider;
        dst.set(i, 0, tmp);
    }
}

template <uint16_t DSTR, uint16_t DSTC>
/* Return Row Vector */
void MeanOfCol(matrix_t dst, matrix_t src) {
    /* Do Summation (Size of Dst will be adjusted here )*/
    SumOfRow<DSTR, DSTC>(dst, src);
    /* Divide */
    data_t divider = src.row();
    foreach (i, DSTC, dst.col()) {
        data_t tmp = dst.get(0, i) / divider;
        dst.set(0, i, tmp);
    }
}

}  // namespace wamatrix
