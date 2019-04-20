/**
 * @file
 * @brief 
 * @author SavaLione
 * @date 21 Apr 2019
*/
/**
 * @defgroup loopconections_cpp LoopConnections.cpp
 * @ingroup client
 * @{
 */
#include "LoopConnections.h"

#include "../Client.h"

#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>

/**
 * |user_check true|user_check false|user pass true|user pass false|
 * [ ][ ][ ][ ]
 */
void loopconn(int const& PORT, std::string const& s_ip)
{
	spdlog::info("|user_check true|user_check false|user pass true|user pass false|");
	spdlog::info("|---------------|----------------|--------------|---------------|");
	int connections = 0;
	int k = 0;
	int err[] = { 0, 0, 0, 0};
	while(true)
	{
		bool bt[] = { true, true , true, true};
		{
			std::string msg = "user_check:[SavaLione]";
			Client ct;
			ct.setPort(PORT);
			ct.setIp(s_ip);
			ct.connect();
			ct.send(msg);
			if(ct.receive() != "answer:[true]")
			{
				bt[0] = false;
				err[0]++;
			}
		}

		{
			std::string msg = "user_check:[NOTNOTNOT]";
			Client ct;
			ct.setPort(PORT);
			ct.setIp(s_ip);
			ct.connect();
			ct.send(msg);
			if(ct.receive() != "answer:[false]")
			{
				bt[1] = false;
				err[1]++;
			}
		}

		{
			std::string msg = "user:[OwO] pass:[OwO]";
			Client ct;
			ct.setPort(PORT);
			ct.setIp(s_ip);
			ct.connect();
			ct.send(msg);
			if(ct.receive() == "answer:[false]")
			{
				bt[2] = false;
				err[2]++;
			}
		}

		{
			std::string msg = "user:[Hewwwoo] pass:[Hiii]";
			Client ct;
			ct.setPort(PORT);
			ct.setIp(s_ip);
			ct.connect();
			ct.send(msg);
			if(ct.receive() == "answer:[true]")
			{
				bt[3] = false;
				err[4]++;
			}
		}
		connections = connections + 4;
		if (connections > 1000)
		{
			k++;
			connections = 0;
			spdlog::info("{}{}{}{} {}", err[0], err[1], err[2], err[3], k);
		}
	}
}

/** @} */