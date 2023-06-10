#ifndef TEXT_AND_COLORS_MGRHANDLER_H
#define TEXT_AND_COLORS_MGRHANDLER_H

#include <cstdint>

#include "MgrBase.h"

struct MgrHandlerCfg;

class MgrHandler {
public:
    int32_t init(const MgrHandlerCfg& cfg);

    void deinit();

    void process();

private:
    void nuliftGlobalMgr(int32_t mgrIdx);

    MgrBase* managers_[MANAGERS_COUNT];
};


#endif //TEXT_AND_COLORS_MGRHANDLER_H
