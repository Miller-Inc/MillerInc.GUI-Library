//
// Created by James Miller on 11/1/24.
//

#ifndef LINUXBUTTON_H
#define LINUXBUTTON_H

#include "../../../CrossPlatform.h"

#ifdef LINUX

#include <X11/Xlib.h>
#include "../../Components/Button.h"

class LinuxButton : public Button
{
public:
    LinuxButton(int id, int x, int y, int width, int height, const std::string& label, Display* display, Window parent);
    void draw() const override;

    void setPos(int x, int y) override;
    void setSize(int width, int height) override;
    void setLabel(const std::string& label) override;
    void setColor(unsigned long color) override;


private:
    Display* display;
    Window parent;
    Window button;
};

#endif //LINUX

#endif //LINUXBUTTON_H
