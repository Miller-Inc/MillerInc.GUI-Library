//
// Created by James Miller on 11/1/2024.
//
#include "../../../include/Window/Windows/Components/WindowsLabel.h"

#ifdef WINDOWS

#include <iostream>

WindowsLabel::WindowsLabel(int id, int width, int height, int x, int y, const std::string& text)
    : Label(id, x, y, width, height, text) {}

void WindowsLabel::draw() const {
    std::cout << "Drawing Windows label: " << text << std::endl;

    HWND hwnd = GetConsoleWindow();
    HDC hdc = GetDC(hwnd);

    RECT rect;
    SetRect(&rect, x, y, x + width, y + height);

    DrawText(hdc, text.c_str(), -1, &rect, DT_SINGLELINE | DT_NOCLIP);

    ReleaseDC(hwnd, hdc);
}

#endif