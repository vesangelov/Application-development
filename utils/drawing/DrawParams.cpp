#include "DrawParams.h"

void DrawParams::reset() {
    pos = Point::UNDEFINED;

    frameRect = Rectangle::ZERO;

    rotationAngle = 0.0;

    width = 0;
    height = 0;

    opacity = FULL_OPACITY;

    rsrcId = INVALID_RSRC_ID;

    widgetType = WidgetType::UNKNOWN;
    flipType = WidgetFlip::NONE;
}