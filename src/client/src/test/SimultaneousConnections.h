/**
 * @file
 * @brief 
 * @author SavaLione
 * @date 24 Apr 2019
*/
/**
 * @defgroup simultaneousconnections_h SimultaneousConnections.h
 * @ingroup client
 * @{
 */
#ifndef SIMULTANEOUSCONNECTIONS_H
#define SIMULTANEOUSCONNECTIONS_H

#include <string>

void noDatabaseConnection(int const& PORT, std::string const& IP);
void withDatabaseConnection(int const& PORT, std::string const& IP);
void withDatabaseMemoryConnection(int const &PORT, std::string const &IP);

#endif // SIMULTANEOUSCONNECTIONS_H
/** @} */