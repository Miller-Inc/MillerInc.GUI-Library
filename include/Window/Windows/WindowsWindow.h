//
// Created by James Miller on 10/30/2024.
//

#ifndef WINDOWSWINDOW_H
#define WINDOWSWINDOW_H

#include "../../../include/Window/CustomWindow.h"
#include <iostream>

#if defined WINDOWS

class WindowsWindow : public CustomWindow
{
public: // Public methods
    WindowsWindow(int width, int height, int x, int y, const std::string* title);

    ~WindowsWindow(); // Destructor

protected:

    static LRESULT WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

    int wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow) const;

public:

    void show() override;

};

#endif //WINDOWS

#endif //WINDOWSWINDOW_H
