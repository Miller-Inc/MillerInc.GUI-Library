//
// Created by James Miller on 10/31/2024.
//

#ifndef LINUXWINDOW_H
#define LINUXWINDOW_H

#include "../../../include/Window/Window.h"
#include <X11/Xlib.h>
#include <string>

#if defined LINUX || defined DEBUG

class LinuxWindow : public Window
{
public:
    LinuxWindow(int width, int height, int x, int y, const std::string* title);
    ~LinuxWindow();

    void show() override;

private:
    Display* display{};
    Window window;
    Atom wmDeleteMessage{};
};

#endif //LINUX

#endif //LINUXWINDOW_H
