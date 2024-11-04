//
// Created by James Miller on 11/1/2024.
//

#ifndef WINDOWSBUTTON_H
#define WINDOWSBUTTON_H

#include "../../../CrossPlatform.h"

#ifdef WINDOWS

#include "../../Components/Button.h"

class WindowsButton : public Button {
public:
    WindowsButton(int id, int width, int height, int x, int y, const std::string& label);
    void draw() const override;
};

#endif

#endif //WINDOWSBUTTON_H
