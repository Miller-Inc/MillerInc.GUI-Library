//
// Created by James Miller on 10/30/2024.
//

#include "../../include/Window/Window.h"

#include <iostream>

Window::Window(const int width, const int height, int x, int y, const std::string* title)
{
    this->width = width;
    this->height = height;
    this->x = x;
    this->y = y;
    this->title = title;
}

Window::~Window()
{
    delete title;
}

void Window::setTitle(const std::string* title)
{
    this->title = title;
}

void Window::setWidth(int width)
{
    this->width = width;
}

void Window::setHeight(int height)
{
    this->height = height;
}

void Window::setX(int x)
{
    this->x = x;
}

void Window::setY(int y)
{
    this->y = y;
}

const std::string* Window::getTitle() const
{
    return title;
}

int Window::getWidth() const
{
    return width;
}

int Window::getHeight() const
{
    return height;
}

int Window::getX() const
{
    return x;
}

int Window::getY() const
{
    return y;
}

void Window::show()
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