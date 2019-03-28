#ifndef BATTLESHIPROYALE_H
#define BATTLESHIPROYALE_H

struct Pos
{
    int i_x;
    int i_y;

};

struct Size
{
    int i_x;
    int i_y;

};

namespace BR
{
    /*
        Info
    */
    const char VERSION_SERVER[] = "Server version: 0.0.1_b";
    const char VERSION_DATABASE[] = "sqlite3 version: 3270200";

    /*
        bd
    */
   const char DB_NAME[] = "test.db";

} // BR


#endif // BATTLESHIPROYALE_H