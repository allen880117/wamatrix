#pragma once
#include "wamatrix_global.hpp"

namespace wamatrix {
/*
 * Matrix Class
 * It only stores the pointer of data.
 * We should declare and link the data by the following macros
 */
typedef class __matrix {
   private:
    /* Pointer of Data */
    data_t *  valPtr;
    uint16_t *rowPtr;
    uint16_t *colPtr;

   public:
    /* Link Data */
    void link(data_t *_valPtr, uint16_t *_rowPtr, uint16_t *_colPtr) {
        this->valPtr = _valPtr;
        this->rowPtr = _rowPtr;
        this->colPtr = _colPtr;
    }

    /* Set Value */
    void set(uint16_t _r, uint16_t _c, data_t _v) {
        this->valPtr[_r * (*(this->colPtr)) + _c] = _v;
    }

    /* Get Value */
    data_t get(uint16_t _r, uint16_t _c) {
        return this->valPtr[_r * (*(this->colPtr)) + _c];
    }

    /* Adjust Size */
    void adjust_size(uint16_t _r, uint16_t _c) {
        *(this->rowPtr) = _r;
        *(this->colPtr) = _c;
    }

    /* Get Row */
    uint16_t row() { return *(this->rowPtr); }

    /* Get Column */
    uint16_t col() { return *(this->colPtr); }
} matrix_t;

}  // namespace wamatrix

/* Declare the Data of Matrix_t Type */
#define DECL_MATRIX(NAME, SIZE)             \
    wamatrix::matrix_t NAME;                \
    data_t             NAME##_valPtr[SIZE]; \
    uint16_t           NAME##_row;          \
    uint16_t           NAME##_col;

/* Link the Data with Matrix_t */
#define LINK_MATRIX(NAME) \
    NAME.link(NAME##_valPtr, &(NAME##_row), &(NAME##_col));