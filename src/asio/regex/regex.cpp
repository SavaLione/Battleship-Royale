#include <iostream>
#include <string>

#include <boost/regex.hpp>

using namespace std;

int main()
{
    cout << "regex"
         << "test" << endl
         << endl;

    std::string xStr("AAAA-12222-BBBBB-44455");
    boost::regex xRegEx("(\\w+)-(\\d+)-(\\w+)-(\\d+)");
    boost::smatch xResults;
    std::cout << "==========================Results============================== \n";
    std::cout << "Does this line match our needs? " << std::boolalpha << boost::regex_match(xStr, xResults, xRegEx) << "\n";
    std::cout << "Print entire match:\n " << xResults[0] << std::endl;
    std::cout << "Print the former string into another format:\n"
              << xResults[1] << "+"
              << xResults[2] << "+"
              << xResults[3] << "+"
              << xResults[4] << std::endl;

    return 0;
}