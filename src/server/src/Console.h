#ifndef CONSOLE_H
#define CONSOLE_H

#include <string>

namespace BR
{
    class Console
    {
    private:
        enum commands
        {
            HELP,
            EXIT,
            SHUTDOWN,
            RESET,
            NOT_FOUND = 1024
        };
        void process(std::string const& command);
        void start();
        commands getCommand(std::string const& command);
    public:
        Console();
        ~Console();
    };
} // namespace BR


#endif // CONSOLE_H