//
// Created by James Miller on 10/30/2024.
//

#ifndef WINDOWSWINDOW_H
#define WINDOWSWINDOW_H

#include "../../../include/Window/Window.h"
#include <iostream>

#if defined WINDOWS

class Window;

class WindowsWindow : public Window
{
public: // Public methods
    WindowsWindow(int width, int height, int x, int y, const std::string* title);

    ~WindowsWindow(); // Destructor

    static LRESULT WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

    int wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow) const;

    void show() override;

};

#endif //WINDOWS

#endif //WINDOWSWINDOW_H
