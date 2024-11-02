//
// Created by James Miller on 11/1/24.
//

#include "../../../../include/Window/Linux/Components/LinuxLabel.h"

#ifdef LINUX

LinuxLabel::LinuxLabel(int id, int x, int y, int width, int height, const std::string& text, Display* display, Window parent)
    : Label(id, x, y, width, height, text), display(display), parent(parent)
{
    labelWindow = XCreateSimpleWindow(display, parent, x, y, width, height, 1,
                                      BlackPixel(display, DefaultScreen(display)),
                                      WhitePixel(display, DefaultScreen(display)));
    XStoreName(display, labelWindow, text.c_str());
    XSelectInput(display, labelWindow, ExposureMask);
    XMapWindow(display, labelWindow);
}

void LinuxLabel::draw() const
{
    GC gc = XCreateGC(display, labelWindow, 0, nullptr);
    XSetForeground(display, gc, BlackPixel(display, DefaultScreen(display)));
    XDrawString(display, labelWindow, gc, 10, 20, label.c_str(), label.length());
    XFreeGC(display, gc);
}

#endif //LINUX