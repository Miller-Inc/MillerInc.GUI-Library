//
// Created by James Miller on 11/1/24.
//

#include "../../../../include/CrossPlatform.h"

#ifdef LINUX

#include "../../../../include/Window/Linux/Components/LinuxButton.h"

LinuxButton::LinuxButton(int id, int x, int y, int width, int height, const std::string& label, Display* display, Window parent)
    : Button(id, x, y, width, height, label), display(display), parent(parent)
{
    button = XCreateSimpleWindow(display, parent, x, y, width, height, 1,
                                 BlackPixel(display, DefaultScreen(display)),
                                 WhitePixel(display, DefaultScreen(display)));
    XStoreName(display, button, label.c_str());
    XSelectInput(display, button, ExposureMask | ButtonPressMask);
    XMapWindow(display, button);
}

void LinuxButton::draw() const
{
    GC gc = XCreateGC(display, button, 0, nullptr);
    XSetForeground(display, gc, BlackPixel(display, DefaultScreen(display)));
    XDrawString(display, button, gc, 10, 20, label.c_str(), label.length());
    XFreeGC(display, gc);
}

void LinuxButton::setPos(int x, int y)
{
    this->x = x;
    this->y = y;
    XMoveWindow(display, button, x, y);
}

void LinuxButton::setSize(int width, int height)
{
    this->width = width;
    this->height = height;
    XResizeWindow(display, button, width, height);
}

void LinuxButton::setLabel(const std::string& label)
{
    this->label = label;
    XStoreName(display, button, label.c_str());
}

void LinuxButton::setColor(unsigned long color)
{
    XSetWindowBackground(display, button, color);
    XClearWindow(display, button);
}

#endif //LINUX
