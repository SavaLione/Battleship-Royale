#ifndef CONSOLE_H
#define CONSOLE_H

#include <string>

namespace BR
{
    class Console
    {
    private:
        void process(std::string const& command);
        void start();
    public:
        Console();
        ~Console();
    };
} // namespace BR


#endif // CONSOLE_H