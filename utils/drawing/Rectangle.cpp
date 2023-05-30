#include "Rectangle.h"

const Rectangle Rectangle::ZERO(0, 0, 0, 0);
const Rectangle Rectangle::UNDEFINED(10000, 10000, 10000, 10000);

Rectangle::Rectangle(int32_t inputX, int32_t inputY,
                    int32_t inputWidth, int32_t inputHeight)
    :   x(inputX), y(inputY), w(inputWidth), h(inputHeight) {}

bool Rectangle::operator==(const Rectangle& other) const{
    return (x == other.x) && (y == other.y)
    && (w == other.w) && (h == other.h);
}

bool Rectangle::operator!=(const Rectangle& other) const{
    return !(*this == other);
}

bool Rectangle::isPointInside(const Point& point) const{
    const bool isInsideX = (x <= point.x) && (point.x < x + w);

    const bool isInsideY = (y <= point.y) && (point.y < y + h);

    return isInsideX &&isInsideY;
}