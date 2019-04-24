/**
 * @file
 * @brief 
 * @author SavaLione
 * @date 24 Apr 2019
*/
/**
 * @defgroup simultaneousconnections_cpp SimultaneousConnections.cpp
 * @ingroup client
 * @{
 */
#include "SimultaneousConnections.h"

#include "../Client.h"

#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>

void noDatabaseConnection(int const &PORT, std::string const &IP)
{
    int connections = 0, k = 0, error = 0;
    while (true)
    {
        std::string msg = "test_without_db";
        Client ct;
        ct.setPort(PORT);
        ct.setIp(IP);
        ct.connect();
        ct.send(msg);
        if (ct.receive() != "test_without_db_from_server")
        {
            error++;
        }
        connections++;
        if (connections > 1000)
        {
            k++;
            connections = 0;
            spdlog::info("nDC {} {}", error, k);
        }
    }
}

void withDatabaseConnection(int const &PORT, std::string const &IP)
{
    int connections = 0, k = 0, error = 0;
    while (true)
    {
        std::string msg = "user_check:[OwO]";
        Client ct;
        ct.setPort(PORT);
        ct.setIp(IP);
        ct.connect();
        ct.send(msg);
        if (ct.receive() != "answer:[true]")
        {
            error++;
        }
        connections++;
        if (connections > 1000)
        {
            k++;
            connections = 0;
            spdlog::info("wDC {} {}", error, k);
        }
    }
}

void withDatabaseMemoryConnection(int const &PORT, std::string const &IP)
{
    int connections = 0, k = 0, error = 0;
    while (true)
    {
        std::string msg = "user:[OwO] pass:[OwO]";
        Client ct;
        ct.setPort(PORT);
        ct.setIp(IP);
        ct.connect();
        ct.send(msg);
        if (ct.receive() != "OWWO111OwO123OwO111OwO")
        {
            error++;
        }
        connections++;
        if (connections > 1000)
        {
            k++;
            connections = 0;
            spdlog::info("wDMC {} {}", error, k);
        }
    }
}

/** @} */