#ifndef UNTITLED_POINT_H
#define UNTITLED_POINT_H

#include <cstdint>

struct Point {
    Point() = default;
    Point(int32_t inputX, int32_t inputY);
    bool operator==(const Point& other) const;
    bool operator!=(const Point& other) const;

    int32_t x = 0;
    int32_t y = 0;

    static const Point ZERO;
    static const Point UNDEFINED;
};

#endif //UNTITLED_POINT_H