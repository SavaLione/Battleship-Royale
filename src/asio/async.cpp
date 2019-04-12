#include "Server.h"
#include "con_handler.h"

#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/enable_shared_from_this.hpp>

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