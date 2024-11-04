//
// Created by James Miller on 11/1/2024.
//

#include "../../../include/Window/Windows/Components/WindowsButton.h"

#ifdef WINDOWS
#include <iostream>

WindowsButton::WindowsButton(int id, int width, int height, int x, int y, const std::string& label)
    : Button(id, width, height, x, y, label) {}

void WindowsButton::draw() const {
    std::cout << "Drawing Windows button: " << label << std::endl;

    HWND hwnd = GetConsoleWindow();
    HDC hdc = GetDC(hwnd);

    RECT rect;
    SetRect(&rect, x, y, x + width, y + height);

    DrawText(hdc, label.c_str(), -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);

    ReleaseDC(hwnd, hdc);
}

#endif