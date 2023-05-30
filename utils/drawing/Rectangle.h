#include <cstdint>

#include "Point.h"

struct Rectangle {
    Rectangle() = default;
    Rectangle(int32_t inputX, int32_t inputY,
              int32_t inputWidth, int32_t inputHeight);

    bool operator==(const Rectangle& other) const;
    bool operator!=(const Rectangle& other) const;

    bool isPointInside(const Point& point) const;

    int32_t x = 0;
    int32_t y = 0;
    int32_t w = 0;
    int32_t h = 0;

    static const Rectangle ZERO;
    static const Rectangle UNDEFINED;
};

