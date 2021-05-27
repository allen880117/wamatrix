#pragma once

#ifndef _WAMX_BASIC_HPP_
#define _WAMX_BASIC_HPP_

#include "wamx_global.hpp"

namespace wamx {
/*
 * Matrix Class
 * It only stores the pointer of data.
 * We should declare and link the data by the following macros
 */
template <uint32_t SIZE>
class Matrix {
   public:
    /* Pointer of Data */
    data_t   val[SIZE];
    uint16_t row;
    uint16_t col;

   public:
    /* Set Value */
    void set(uint16_t _r, uint16_t _c, data_t _v) {
        this->val[_r * (this->col) + _c] = _v;
    }

    /* Get Value */
    data_t get(uint16_t _r, uint16_t _c) {
        return this->val[_r * (this->col) + _c];
    }

    /* Adjust Size */
    void adjust_size(uint16_t _r, uint16_t _c) {
        this->row = _r;
        this->col = _c;
    }
};

}  // namespace wamx

#define ADJ_SIZE_MATRIX(NAME, R, C) NAME.adjust_size((R), (C));
#define ADJ_SIZE_ROWVEC(NAME, C) NAME.adjust_size((1), (C));
#define ADJ_SIZE_COLVEC(NAME, R) NAME.adjust_size((R), (1));

#define PrintMatrix(mat)                                        \
    std::cout << std::endl;                                     \
    for (uint16_t i = 0; i < (mat.row); i++) {                  \
        for (uint16_t j = 0; j < (mat.col); j++) {              \
            std::cout << std::setw(15) << mat.get(i, j) << " "; \
        }                                                       \
        std::cout << std::endl;                                 \
    }                                                           \
    std::cout << std::endl;

#endif