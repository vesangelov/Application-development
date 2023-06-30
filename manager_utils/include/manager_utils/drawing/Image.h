#ifndef MANAGERS_IMAGE_H
#define MANAGERS_IMAGE_H

#include "Widget.h"

class Image : public Widget{
public:
    ~Image();

    void create(int32_t rsrcId, const Point& pos = Point::ZERO);
    void destroy();

    void setFrame(int32_t frameIdx);
    void setNextFrame();
    void setPrevFrame();
    int32_t getFrame() const;


    //const Frames& getImageFrames(int32_t rsrcId) const;
private:
    int32_t _currFrame { 0 };
    int32_t _maxFrames { 0 };
};


#endif //MANAGERS_IMAGE_H
