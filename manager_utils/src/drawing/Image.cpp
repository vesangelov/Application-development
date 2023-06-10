#include "../../include/manager_utils/drawing/Image.h"
#include "../../../manager_utils/include/manager_utils/managers/ResMgr.h"

#include <iostream>

Image::~Image() {
    if(_isCreated && !_isDestroyed){
        destroy();
    }
}

void Image::create(int32_t rsrcId, const Point& pos){

    if(_isCreated){
        std::cerr << "Error, image with rsrcId: " << rsrcId
        << " was already created. Will not create twice" << std::endl;
        return;
    }

    const auto rect = gResMgr->getImageFrame(rsrcId);
    _drawParams.rsrcId = rsrcId;
    _drawParams.width = rect.w;
    _drawParams.height = rect.h;
    _drawParams.pos = pos;
    _drawParams.widgetType = WidgetType::IMAGE;

    _isCreated = true;
    _isDestroyed = false;
}

void Image::destroy(){
    if(!_isCreated){
        std::cerr << "Error, image was already destroyed" << std::endl;
        return;
    }

    _isCreated = false;
    _isDestroyed = true;

    Widget::reset();
}
