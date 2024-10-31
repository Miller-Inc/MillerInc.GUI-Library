//
// Created by James Miller on 10/30/2024.
//

#ifndef WINDOW_H
#define WINDOW_H
#include <string>

#include "../../include/CrossPlatform.h"

class Window
{
private:
    int width, height;
    int x, y;

    const std::string* title;

public:
    Window(int width, int height, int x, int y, const std::string* title);
    ~Window();

    virtual void setTitle(const std::string* title);
    virtual void setWidth(int width);
    virtual void setHeight(int height);
    virtual void setX(int x);
    virtual void setY(int y);

    [[nodiscard]] const std::string* getTitle() const;
    [[nodiscard]] int getWidth() const;
    [[nodiscard]] int getHeight() const;
    [[nodiscard]] int getX() const;
    [[nodiscard]] int getY() const;

    [[nodiscard]] virtual void show();


};


#endif //WINDOW_H
