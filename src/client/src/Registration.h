/**
 * @file
 * @brief 
 * @author SavaLione
 * @date 22 Apr 2019
*/
/**
 * @defgroup registration_h Registration.h
 * @ingroup client
 * @{
 */
#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <string>

#if _WIN32
#include <ncursesw/curses.h>
#include <ncursesw/form.h>
#elif __unix__
#include <ncurses/curses.h>
#include <ncurses/form.h>
#endif

#include <cstring>

class Registration
{
private:
public:
    Registration();
    ~Registration();
};

#endif // REGISTRATION_H
/** @} */