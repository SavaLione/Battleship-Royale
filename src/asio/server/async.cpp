#include "Server.h"

#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>

int main(int argc, char *argv[])
{
	try 
	{
		boost::asio::io_service io_service;   
		Server server(io_service);
		io_service.run();
	} 
	catch(std::exception& e) 
	{
		//std::cerr << e.what() << std::endl;
		spdlog::error("Error create Server!");
		spdlog::error(e.what());
	}
	
	return 0;
}