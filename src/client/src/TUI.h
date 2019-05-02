/**
 * @file
 * @brief 
 * @author SavaLione
 * @date 30 Apr 2019
*/
/**
 * @defgroup tui_h TUI.h
 * @ingroup client
 * @{
 */
#ifndef TUI_H
#define TUI_H

#include "BattleshipRoyale.h"

class TUI
{
private:
    void initColor();
    void bottom();

public:
    TUI();
    ~TUI();
    void move();
    BR::CODE::MENU::MAIN::items MainMenu();
    void colorTest();
    void locTest();
};

#endif // TUI_H
/** @} */