//
// Created by James Miller on 10/30/2024.
//

#ifndef WINDOWSWINDOW_H
#define WINDOWSWINDOW_H

#include "../../include/Window/Window.h"
#include <iostream>

class WindowsWindow : public Window
{
    WindowsWindow(const int width, const int height,
        int x, int y, const std::string* title) :
        Window(width, height, x, y, title);

    ~WindowsWindow(); // Destructor


};


#endif //WINDOWSWINDOW_H
