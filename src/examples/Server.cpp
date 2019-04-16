#include <iostream>

#include "Server.h"

int main()
{
    int PORT = 1234;
	try 
	{
		boost::asio::io_service io_service;   
		Server server(io_service, &PORT);
		io_service.run();
	} 
	catch(std::exception& e) 
	{
		std::cout << e.what() << endl;
	}
    return 0;
}