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

class TUI
{
private:
    void initColor();
    void bottom();

public:
    TUI();
    ~TUI();
    void move();
    void MainMenu();
    void colorTest();
    void locTest();
};

#endif // TUI_H
/** @} */