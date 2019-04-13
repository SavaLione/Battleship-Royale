#ifndef REGEX_H
#define REGEX_H

#include <string>

bool check_pattern(std::string *msg, std::string *pattern);
void getData(std::string *msg, std::string *pattern, std::string *ret_one);
void getData(std::string *msg, std::string *pattern, std::string *ret_one, std::string *ret_two);

#endif // REGEX_H