#include "Console.h"

#include <iostream>
#include <future>

#include "BattleshipRoyale.h"

BR::Console::Console()
{
    std::future<void> result(std::async(start, this));
}

BR::Console::~Console()
{
}

void BR::Console::start()
{
    for (std::string line; std::cout << "BR > " && std::getline(std::cin, line);)
    {
        if (!line.empty())
        {
            BR::Console::process(line);
        }
    }
}

void BR::Console::process(std::string const &command)
{
    std::cout << "command " << command << std::endl;
}