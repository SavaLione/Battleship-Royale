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

    string user = "[asd]";
    string user_pass = "[asdasdasd] [asdasdqweasdwq]";
    string uid = "[sdqweascxzdfqew] [asdwq aszxccda awqesd 143dsdasd rfqcv.df.e.]";
    //boost::regex regx_user("\\[([^\\[\\]]+)\\]");
    boost::regex regx_user("\\[.*?\\]");
    boost::smatch smatch_user;
    cout << user        << endl
         << user_pass   << endl
         << uid         << endl;
    cout << "user ok? " << boost::regex_match(user, smatch_user, regx_user) << endl;
    cout << smatch_user[0] << " " << smatch_user[1] << endl;

    cout << "user_pass ok? " << boost::regex_match(user_pass, smatch_user, regx_user) << endl;
    cout << smatch_user[0] << " " << smatch_user[1] << " " << smatch_user[2] << endl;


    return 0;
}