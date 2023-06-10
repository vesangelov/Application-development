#ifndef MANAGERS_IMAGE_H
#define MANAGERS_IMAGE_H

#include "Widget.h"

class Image : public Widget{
public:
    ~Image();

    void create(int32_t rsrcId, const Point& pos = Point::ZERO);
    void destroy();
};


#endif //MANAGERS_IMAGE_H
