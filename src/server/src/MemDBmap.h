/**
 * @file
 * @brief Облегчённый класс для работы с бд в памяти
 * @author SavaLione
 * @date 16 Apr 2019
 */
/**
 * @defgroup memdbmap_h MemDBmap.h
 * @ingroup server
 * @{
 */
#ifndef MEMDBMAP_H
#define MEMDBMAP_H

class MemDBmap
{
public:
    MemDBmap();
    ~MemDBmap();
    void create();
};

#endif // MEMDBMAP_H
/** @} */