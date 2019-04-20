#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>

void test();

int main()
{
    spdlog::set_level(spdlog::level::critical);

    auto file_logger = spdlog::basic_logger_mt("BR", "Battleship-Royale.log");
    spdlog::set_default_logger(file_logger);

    spdlog::info("Welcome to spdlog!");
    spdlog::error("Some error message with arg: {}", 1);
    
    spdlog::warn("Easy padding in numbers like {:08d}", 12);
    spdlog::critical("Support for int: {0:d};  hex: {0:x};  oct: {0:o}; bin: {0:b}", 42);
    spdlog::info("Support for floats {:03.2f}", 1.23456);
    spdlog::info("Positional args are {1} {0}..", "too", "supported");
    spdlog::info("{:<30}", "left aligned");
    
    spdlog::debug("This message not should be displayed..");    

    file_logger->info("SOME INFO {}", 1);
    file_logger->info("SOME INFO {}", 2);
    file_logger->info("SOME INFO {}", 3);
    file_logger->critical("SOME INFO {}", 4);
    file_logger->critical("SOME INFO {}", 5);
    file_logger->critical("SOME INFO {}", 6);

    test();

    return 0;
}

void test()
{
    spdlog::info("Welcome to spdlog!");
    spdlog::error("Some error message with arg: {}", 1);
    
    spdlog::warn("Easy padding in numbers like {:08d}", 12);
    spdlog::critical("Support for int: {0:d};  hex: {0:x};  oct: {0:o}; bin: {0:b}", 42);
    spdlog::info("Support for floats {:03.2f}", 1.23456);
    spdlog::info("Positional args are {1} {0}..", "too", "supported");
    spdlog::info("{:<30}", "left aligned");
    
    spdlog::debug("This message not should be displayed..");    
}