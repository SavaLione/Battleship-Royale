#include <iostream>
#include <string>

#include <boost/regex.hpp>

using namespace std;

void test();
void test1();
void test2();
void test3();
void test4();

int main()
{
    test3();
    test4();
    return 0;
}

void test4()
{
    string msg = "user:[savalione] pass:[mypass]";
    string s_regx = "^user:\\[([^\\[\\]]+)\\] pass:\\[([^\\[\\]]+)\\]$";
    cout << "s_regx: " << s_regx << endl;
    boost::regex reg_ex(s_regx);
    cout << "regex_match(msg, reg_ex): " << boost::regex_match(msg, reg_ex) << std::endl;
}

void test3()
{
    string msg = "user:[savalione]";
    string s_regx = "^user:\\[([^\\[\\]]+)\\]$";
    cout << "s_regx: " << s_regx << endl;
    boost::regex reg_ex(s_regx);
    cout << "regex_match(msg, reg_ex): " << boost::regex_match(msg, reg_ex) << std::endl;
}

void test2()
{
    /* Our strings and string forms for the regualr expressions. */
    char const *s1 = "hello, world";
    char const *s2 = "hello, world!  hello, bob!";
    char const *es1 = "hello";
    char const *es2 = ".*hello.*";
    char const *es3 = ".*(hello).*(world).*";

    /* Build (compile) our regular expressions */
    boost::regex e1(es1);
    boost::regex e2(es2);
    boost::regex e3(es3);

    /* A place to put matchs (and sub-matchs) */
    boost::cmatch what;

    /* The thing to note is that the re must match the ENTIRE string. */
    std::cout << "regex_match(s1, e1): " << boost::regex_match(s1, e1) << std::endl;
    std::cout << "regex_match(s1, e2): " << boost::regex_match(s1, e2) << std::endl;

    /* We can find sub-expressions with regex_match too */
    std::cout << "regex_match(s1, what, e3): " << boost::regex_match(s1, what, e3) << std::endl;
    std::cout << "what[0] = " << std::string(what[0].first, what[0].second) << std::endl;
    std::cout << "what[1] = " << std::string(what[1].first, what[1].second) << std::endl;
    std::cout << "what[2] = " << std::string(what[2].first, what[2].second) << std::endl;

    /* You can use regex_format to build perl-like subistitution rules. */
    std::cout << "Perl like expand ('$1-$2') = " << regex_format(what, "$1-$2") << std::endl;

    /* regex_match can be used much like the s// operator in perl */
    std::cout << "perlish s2=~s/e1/HELLO/g: " << regex_merge(std::string(s2), e1, "HELLO") << std::endl;

    /* Note that with regex_search, we don't have to match the whole line. */
    std::cout << "regex_search(s1, what, e1): " << boost::regex_search(s1, what, e1) << std::endl;
    std::cout << "what[0] = " << std::string(what[0].first, what[0].second) << std::endl;
}

void test()
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

    string user = "name:[asd]";
    string user_pass = "[asdasdasd] [asdasdqweasdwq]";
    string uid = "[sdqweascxzdfqew] [asdwq aszxccda awqesd 143dsdasd rfqcv.df.e.]";
    //boost::regex regx_user("\\[([^\\[\\]]+)\\]");
    boost::regex regx_user("\\[.*?\\]");
    boost::smatch smatch_user;
    cout << user << endl
         << user_pass << endl
         << uid << endl;
    cout << "user ok? " << boost::regex_match(user, smatch_user, regx_user) << endl;
    cout << smatch_user[0] << " " << smatch_user[1] << endl;

    cout << "user_pass ok? " << boost::regex_match(user_pass, smatch_user, regx_user) << endl;
    cout << smatch_user[0] << " " << smatch_user[1] << " " << smatch_user[2] << endl;

    cout << "uid ok? " << boost::regex_match(uid, smatch_user, regx_user) << endl;
    cout << smatch_user[0] << " " << smatch_user[1] << " " << smatch_user[2] << endl;
}

void test1()
{
    std::string xStr("name:[asdasdasd] pass:[qsdqsffdffsdf] somedata:[asdasd asdasd asdasd asdasd] one:[asdasd]");
    boost::regex xRegEx("\\[([^\\[\\]]+)\\]");
    boost::smatch xResults;
    std::cout << "==========================Results============================== \n";
    std::string::const_iterator xItStart = xStr.begin();
    std::string::const_iterator xItEnd = xStr.end();
    int iter = 0;

    /*
    while (boost::regex_search(xItStart, xItEnd, xResults, xRegEx))
    {
        cout << xResults[0] << " " << xResults[2];
        xItStart = xResults[1].second;
        iter++;
    }
    */
    string s_test = "";
    while (boost::regex_search(xItStart, xItEnd, xResults, xRegEx))
    {
        cout << xResults[iter] << " " << endl;
        s_test += xResults[iter];
        xItStart = xResults[iter].second;
        iter++;
    }

    cout << "iter: " << iter << endl;
    cout << "s_test: " << s_test << endl;
}
