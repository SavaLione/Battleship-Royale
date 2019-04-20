/**
 * @file
 * @brief 
 * @author SavaLione
 * @date 21 Apr 2019
*/
/**
 * @defgroup args_h Args.h
 * @ingroup client
 * @{
 */
#ifndef ARGS_H
#define ARGS_H

#include <string>

void arg(int argc, char *argv[], int& LOG_LEVEL, int& PORT, std::string& s_ip, std::string& s_test);

#endif // ARGS_H
/** @} */