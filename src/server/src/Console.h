#ifndef CONSOLE_H
#define CONSOLE_H

#include <string>

namespace BR::CONSOLE
{
    enum CMD
    {
        HELP,
        EXIT,
        SHUTDOWN,
        RESET,
        NOT_FOUND = 1024
    };

    void process(std::string const& command);
    CMD getCommand(std::string const& command);
    void start();

} // namespace BR::CONSOLE


#endif // CONSOLE_H