#pragma once

#ifndef _WAMX_GLOBAL_HPP_
#define _WAMX_GLOBAL_HPP_

#include <cmath>

/* General Integer Type */
typedef unsigned short uint16_t;
typedef unsigned int   uint32_t;

/* General Float-Point Type */
typedef float  data_t;

/* HLS Pragma */
#define Pragma(x) _Pragma(#x)
#define HLS(directive) Pragma(hls directive)

/* Macro of For Loop */
#define foreach(I, MAX_ITER_SIZE, ITER_SIZE)       \
    for (uint16_t I = 0; I < (MAX_ITER_SIZE); I++) \
        if (I < (ITER_SIZE))

/* Macro of For Loop With Pipeline Directive */
#define foreach_pipeline(I, MAX_ITER_SIZE, ITER_SIZE)            \
    for (uint16_t I = 0; I < (MAX_ITER_SIZE); I++) HLS(pipeline) \
    if (I < (ITER_SIZE))

#endif