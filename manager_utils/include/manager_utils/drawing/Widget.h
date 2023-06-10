#ifndef MANAGERS_WIDGET_H
#define MANAGERS_WIDGET_H

#include <iostream>

#include "../../../../utils/drawing/DrawParams.h"

class Widget {
public:
    void draw();

    void reset();

    void setWidth(int32_t width);
    void setHeight(int32_t height);

    int32_t getWidth() const;
    int32_t getHeight() const;

    void setPosition(const Point& pos);
    void setPosition(int32_t x, int32_t y);
    void setOpacity(int32_t opacity);

    int32_t getOpacity() const;
    Point getPosition() const;

    void show();

    void hide();

    void activateAlphaModulation();
    void deactivateAlphaModulation();

    void moveRight(int32_t delta);
    void moveLeft(int32_t delta);
    void moveUp(int32_t delta);
    void moveDown(int32_t delta);

//move methods could be added for convenience
//show & hide methods could also be implemented for convenience

protected:
    DrawParams _drawParams;

    bool _isCreated = false;
    bool _isDestroyed = true;
    bool _isVisible = true;
    bool _isAlphaModulationEnabled = false;
};

#endif //MANAGERS_WIDGET_H
