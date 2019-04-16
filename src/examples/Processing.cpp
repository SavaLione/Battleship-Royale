#include <string>
#include <iostream>

#include "Processing.h"

int main()
{
    std::string request = "user_check:[SavaLione]";
    Processing prc;
    std::cout << prc.response(request) << std::endl;
    return 0;
}