//
// Created by James Miller on 10/30/2024.
//

#ifndef WINDOW_H
#define WINDOW_H
#include <string>
#include <vector>

#include "Components.h"
#include "../../include/CrossPlatform.h"

class CustomWindow
{
protected:
    int width = 800, height = 600;
    int x = 0, y = 0;

    const std::string* title = new std::string("new window");

public:
    CustomWindow(int width, int height, int x, int y, const std::string* title);
    virtual ~CustomWindow();

    virtual void setTitle(const std::string* title);
    virtual void setWidth(int width);
    virtual void setHeight(int height);
    virtual void setX(int x);
    virtual void setY(int y);
    virtual bool running()
    {
        return isRunning;
    }

    [[nodiscard]] const std::string* getTitle() const;
    [[nodiscard]] int getWidth() const;
    [[nodiscard]] int getHeight() const;
    [[nodiscard]] int getX() const;
    [[nodiscard]] int getY() const;

    virtual void show();
    virtual void update();

    virtual void addItem(Item* item);
    virtual void addButton(Button* button);
    virtual void addLabel(Label* label);

protected:
    volatile bool isRunning = false;
    std::vector<Item*> WindowItems;



};


#endif //WINDOW_H
