#include "Server.h"

#include <iostream>

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
		std::cerr << e.what() << std::endl;
	}
	
	return 0;
}