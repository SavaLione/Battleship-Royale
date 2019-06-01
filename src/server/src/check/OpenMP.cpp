/**
 * @file
 * @brief Проверка поддержки OpenMP
 * @author SavaLione
 * @date 20 Apr 2019
*/
/**
 * @defgroup openmp_cpp OpenMP.cpp
 * @ingroup battleship-royale
 * @{
 */
#include "OpenMP.h"

int BR::CHECK::openmp()
{
    int ret = 0;
#ifdef _OPENMP
    #pragma omp parallel reduction (+:ret)
    {
        #pragma omp atomic
	    ret++;
    }
        return ret;
#else
    return -1;
#endif
}

/** @} */