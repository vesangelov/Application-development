#ifndef MANAGERS_TEXT_H
#define MANAGERS_TEXT_H

#include "Widget.h"
#include "../../../../utils/drawing/Color.h"

class Text : public Widget {
public:
    ~Text();

    void create(const std::string& text,  int32_t fontId,
                const Color& color, const Point &pos = Point::ZERO);

    void destroy();

    void setText(const char *text);

    void setColor(const Color& color);

    std::string getTextContent() const;

private:
    std::string _textContent;
    Color _color = Colors::BLACK;
    int32_t _fontId = INVALID_RSRC_ID;
};


#endif //MANAGERS_TEXT_H
