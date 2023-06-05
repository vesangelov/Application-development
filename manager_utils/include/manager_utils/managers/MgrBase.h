#ifndef TEXT_AND_COLORS_MGRBASE_H
#define TEXT_AND_COLORS_MGRBASE_H

class MgrBase {
public:
    MgrBase() = default;
    virtual ~MgrBase() = default;

    //forbid the copy and move constructors
    //forbid the copy and move assignment operators

    MgrBase(const MgrBase& other) = delete;
    MgrBase(MgrBase&& other) = delete;

    MgrBase& operator=(const MgrBase& other) = delete;
    MgrBase& operator=(MgrBase&& other) = delete;

    virtual void deinit() = 0;
    virtual void process() = 0;
};

#endif //TEXT_AND_COLORS_MGRBASE_H
