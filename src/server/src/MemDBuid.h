/**
 * @file
 * @brief Облегчённый класс для работы с бд в памяти
 * @author SavaLione
 * @date 16 Apr 2019
 */
/**
 * @defgroup memdbuid_h MemDBuid.h
 * @ingroup server
 * @{
 */
#ifndef MEMDBUID_H
#define MEMDBUID_H

#include <string>

class MemDBuid
{
private:
    void setUid(std::string const& name, std::string const& uid);

public:
    MemDBuid();
    ~MemDBuid();
    void create();
    void del();
    void setUid(std::string const& name);
    std::string getUid(std::string const& name);
    std::string getName(std::string const& uid);
    bool checkUid(std::string const& uid);
    bool ifFoundUid(std::string const& uid);
    bool ifFoundName(std::string const& name);
};

#endif // MEMDBUID_H
/** @} */