//
// Created by James Miller on 10/31/2024.
//

#ifndef LINUXWINDOW_H
#define LINUXWINDOW_H

#include "../../../include/Window/CustomWindow.h"

#if defined LINUX || defined DEBUG
#include <X11/Xlib.h>
#include <string>

#include <vector>

#include "../Components.h"
#include "Components/LinuxButton.h"


class LinuxWindow : public CustomWindow
{
public:
    LinuxWindow(int width, int height, int x, int y, const std::string* title);
    ~LinuxWindow() override;

    void show() override;
    void update() override;

    void setWindowColor(unsigned long color);
    void setButtonColor(unsigned long color);

    void addButton(Button* button) override;
    void addLabel(Label* label) override;

private:
    Display* display{};
    Window window;
    Atom wmDeleteMessage{};

    unsigned long windowColor;
    unsigned long buttonColor;

    std::vector<LinuxButton> buttons;
};

#endif //LINUX

#endif //LINUXWINDOW_H
