#include <string>
#include <iostream>

#include "Regex.h"

int main()
{
    std::string s = "user:[SavaLione]";
    std::string s_ret_one = "";
    std::string s_ret_two = "";
    std::string s_pattern = "user_check:\\[([^\\[\\]]+)\\]";
    if(check_pattern(s, s_pattern))
    {
        //some if ok
    }

    getData(s, s_pattern, s_ret_one);

    std::cout << "The first finding in the line: " << s_ret_one << std::endl;

    getData(s, s_pattern, s_ret_one, s_ret_two);
    std::cout << "The first finding in the line: " << s_ret_one << std::endl << "The second is in the line. " << s_ret_two << std::endl;

    return 0;
}