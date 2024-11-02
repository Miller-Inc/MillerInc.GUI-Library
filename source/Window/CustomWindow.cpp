//
// Created by James Miller on 10/30/2024.
//

#include "../../include/Window/CustomWindow.h"

#include <iostream>

CustomWindow::CustomWindow(const int width, const int height, int x, int y, const std::string* title)
{
    this->width = width;
    this->height = height;
    this->x = x;
    this->y = y;
    this->title = title;
}

CustomWindow::~CustomWindow() = default;

void CustomWindow::setTitle(const std::string* title)
{
    this->title = title;
}

void CustomWindow::setWidth(int width)
{
    this->width = width;
}

void CustomWindow::setHeight(int height)
{
    this->height = height;
}

void CustomWindow::setX(int x)
{
    this->x = x;
}

void CustomWindow::setY(int y)
{
    this->y = y;
}

const std::string* CustomWindow::getTitle() const
{
    return title;
}

int CustomWindow::getWidth() const
{
    return width;
}

int CustomWindow::getHeight() const
{
    return height;
}

int CustomWindow::getX() const
{
    return x;
}

int CustomWindow::getY() const
{
    return y;
}

void CustomWindow::show()
{
    std::cout << "Window: " << *title << std::endl;
    std::cout << "Width: " << width << std::endl;
    std::cout << "Height: " << height << std::endl;
    std::cout << "X: " << x << std::endl;
    std::cout << "Y: " << y << std::endl;

#ifdef WINDOWS
    std::cout << "OS: Windows" << std::endl;

#elif defined MACOS
    std::cerr << "OS: MacOS Not Supported" << std::endl;
#elif defined LINUX
    std::cout << "OS: Linux" << std::endl;
#endif

}

void CustomWindow::update()
{
    for (const auto& item : WindowItems) {
        item->draw();
    }
}

void CustomWindow::addItem(Item* item)
{
    this->WindowItems.push_back(item);
}

void CustomWindow::addButton(Button* button)
{
    this->WindowItems.push_back(button);
}

void CustomWindow::addLabel(Label* label)
{
    this->WindowItems.push_back(label);
}
