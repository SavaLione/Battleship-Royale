/////////////////////////////////////////////////////////////////////////////
// The Software is provided "AS IS" and possibly with faults. 
// Intel disclaims any and all warranties and guarantees, express, implied or
// otherwise, arising, with respect to the software delivered hereunder,
// including but not limited to the warranty of merchantability, the warranty
// of fitness for a particular purpose, and any warranty of non-infringement
// of the intellectual property rights of any third party.
// Intel neither assumes nor authorizes any person to assume for it any other
// liability. Customer will use the software at its own risk. Intel will not
// be liable to customer for any direct or indirect damages incurred in using
// the software. In no event will Intel be liable for loss of profits, loss of
// use, loss of data, business interruption, nor for punitive, incidental,
// consequential, or special damages of any kind, even if advised of
// the possibility of such damages.
//
// Copyright (c) 2003 Intel Corporation
//
// Third-party brands and names are the property of their respective owners
//
///////////////////////////////////////////////////////////////////////////
// Random Number Generation for SSE / SSE2
// Source File
// Version 0.1
// Author Kipp Owens, Rajiv Parikh
////////////////////////////////////////////////////////////////////////
/**
 * @file
 * @brief Генерация рандомных чисел через SSE
 * @example rand_sse.cpp
 * @deprecated
 * @author Kipp Owens, Rajiv Parikh, SavaLione
 * @date 13 Apr 2019
*/
/**
 * @defgroup rand_sseh rand_sse.h
 * @ingroup server
 * @{
*/
#ifndef RAND_SSE_H
#define RAND_SSE_H

#define COMPATABILITY

/**
 * @brief Задать seed
 * @code
 *      srand_sse(time(NULL));
 * @endcode
 * @param [in] seed Seed
 */
void srand_sse( unsigned int seed );

/**
 * @brief Получение вектора с случайными числами
 * @code
 *      unsigned int u_i_random[4];
 *      rand_sse(u_i_random);
 * @endcode
 * @param [out] result вектор с случайными числами
 */
void rand_sse( unsigned int* result);

#endif // RAND_SSE_H
/** @} */