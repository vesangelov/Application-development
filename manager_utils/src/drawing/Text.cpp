#include "../../include/manager_utils/drawing/Text.h"
#include "../../../manager_utils/include/manager_utils/managers/ResMgr.h"

#include <iostream>

Text::~Text() {
    if(_isCreated && !_isDestroyed){
        destroy();
    }
}

void Text::create(const std::string& text,  int32_t fontId,
            const Color& color, const Point &pos){
    if(_isCreated){
        std::cerr << "Error, text with rsrcId: " << fontId
                  << " was already created. Will not create twice" << std::endl;
        return;
    }

    gResMgr->createText(text, color, fontId, _drawParams.rsrcId,
                        _drawParams.width, _drawParams.height);

    _drawParams.pos = pos;
    _drawParams.widgetType = WidgetType::TEXT;

    _textContent = text;
    _color = color;
    _fontId = fontId;

    _isCreated = true;
    _isDestroyed = false;
}

void Text::destroy(){
    if(!_isCreated){
        std::cerr << "Error, text was already destroyed" << std::endl;
        return;
    }

    _isCreated = false;
    _isDestroyed = true;

    Widget::reset();
}

void Text::setText(const char *text) {

    if(_textContent == text){
        _textContent = text;
        return;
    }

    gResMgr->createText(text, _color, _fontId, _drawParams.textId,
                        _drawParams.width, _drawParams.height);
}

void Text::setColor(const Color& color){
    if(_color == color){
        return;
    }

    gResMgr->createText(_textContent, _color, _fontId, _drawParams.textId,
                        _drawParams.width, _drawParams.height);
}

std::string Text::getTextContent() const{
    return this->_textContent;
}


