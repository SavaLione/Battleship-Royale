#include "Console.h"

#include <iostream>
#include <future>

#include "BattleshipRoyale.h"
#include "MemDBuid.h"

void BR::CONSOLE::start()
{
    for (std::string line; std::cout << BR::CONSOLE::GREETING && std::getline(std::cin, line);)
    {
        if (!line.empty())
        {
            BR::CONSOLE::process(line);
        }
    }
}

void BR::CONSOLE::process(std::string const &command)
{
    CMD c = getCommand(command);
    switch (c)
    {
    case CMD::HELP:
    {
        std::cout << BR::CONSOLE::MESSAGE::HELP << std::endl;
        break;
    }
    case CMD::SHUTDOWN:
    {
        exit(1);
        break;
    }
    case CMD::RESET:
    {
        MemDBuid mdbUid;
        mdbUid.del();
        mdbUid.create();
        break;
    }
    case CMD::EXIT:
    {
        MemDBuid mdbUid;
        mdbUid.del();
        exit(0);
        break;
    }
    case CMD::NOT_FOUND:
    {
        std::cout << BR::CONSOLE::MESSAGE::NOT_FOUND << std::endl;
        break;
    }
    default:
        std::cout << BR::CONSOLE::MESSAGE::NOT_FOUND << std::endl;
        break;
    }
}

BR::CONSOLE::CMD BR::CONSOLE::getCommand(std::string const &command)
{
    CMD ret = BR::CONSOLE::CMD::NOT_FOUND;

    if (command == BR::CONSOLE::COMMANDS::HELP)
        return CMD::HELP;
    
    if (command == BR::CONSOLE::COMMANDS::HELP_SHORT)
        return CMD::HELP;
    
    if (command == BR::CONSOLE::COMMANDS::SHUTDOWN)
        return CMD::SHUTDOWN;
    
    if (command == BR::CONSOLE::COMMANDS::SHUTDOWN_SHORT)
        return CMD::SHUTDOWN;
    
    if (command == BR::CONSOLE::COMMANDS::RESET)
        return CMD::RESET;
    
    if (command == BR::CONSOLE::COMMANDS::RESET_SHORT)
        return CMD::RESET;
    
    if (command == BR::CONSOLE::COMMANDS::EXIT)
        return CMD::EXIT;
    
    if (command == BR::CONSOLE::COMMANDS::EXIT_SHORT)
        return CMD::EXIT;

    return ret;
}