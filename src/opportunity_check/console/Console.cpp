#include <string>
#include <iostream>
#include <conio.h>

#include <future>
#include <unistd.h>

#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>

bool CONSOLE_CHECK = false;

void console();
void test();

int main()
{
    for (std::string line; std::cout << "BR > " && std::getline(std::cin, line);)
    {
        if (!line.empty())
        {
            //process(line);
        }
    }

    std::cout << "Goodbye.\n";
    return 0;
}

void console()
{
    std::future<void> result(std::async(test));
    CONSOLE_CHECK = true;
    while(true)
    {
        if(!CONSOLE_CHECK)
        {
            getch();
            CONSOLE_CHECK = true;
        }
    }
}

void test()
{
    while(true)
    {
        spdlog::info("ASYNC");
        usleep(1000 * 1000 * 3);
    }
}