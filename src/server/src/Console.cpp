#include "Console.h"

#include <iostream>
#include <future>

#include "BattleshipRoyale.h"
#include "MemDBuid.h"

BR::Console::Console()
{
    std::future<void> result(std::async(start, this));
}

BR::Console::~Console()
{
}

void BR::Console::start()
{
    for (std::string line; std::cout << BR::CONSOLE::GREETING && std::getline(std::cin, line);)
    {
        if (!line.empty())
        {
            BR::Console::process(line);
        }
    }
}

void BR::Console::process(std::string const &command)
{
    commands c = getCommand(command);
    switch (c)
    {
    case HELP:
    {
        std::cout << BR::CONSOLE::HELP << std::endl;
        break;
    }
    case SHUTDOWN:
    {
        exit(1);
        break;
    }
    case RESET:
    {
        MemDBuid mdbUid;
        mdbUid.del();
        mdbUid.create();
        break;
    }
    case EXIT:
    {
        MemDBuid mdbUid;
        mdbUid.del();
        exit(0);
        break;
    }
    case NOT_FOUND:
    {
        std::cout << BR::CONSOLE::NOT_FOUND << std::endl;
        break;
    }
    default:
        std::cout << BR::CONSOLE::NOT_FOUND << std::endl;
        break;
    }
}

BR::Console::commands BR::Console::getCommand(std::string const &command)
{
    commands ret = NOT_FOUND;

    if (command == BR::CONSOLE::COMMANDS::HELP)
        return HELP;
    
    if (command == BR::CONSOLE::COMMANDS::HELP_SHORT)
        return HELP;
    
    if (command == BR::CONSOLE::COMMANDS::SHUTDOWN)
        return SHUTDOWN;
    
    if (command == BR::CONSOLE::COMMANDS::SHUTDOWN_SHORT)
        return SHUTDOWN;
    
    if (command == BR::CONSOLE::COMMANDS::RESET)
        return RESET;
    
    if (command == BR::CONSOLE::COMMANDS::RESET_SHORT)
        return RESET;
    
    if (command == BR::CONSOLE::COMMANDS::EXIT)
        return EXIT;
    
    if (command == BR::CONSOLE::COMMANDS::EXIT_SHORT)
        return EXIT;

    return ret;
}