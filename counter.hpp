#ifndef COUNTER_HPP_INCLUDED
#define COUNTER_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"
#include "window.hpp"

class Counter : public Widget {
    bool _ford;
public:
    Counter(int x, int y, int sx, int sy, int num, int mi, int ma, bool ford);
    virtual void draw();
    virtual void write() const;
    virtual void handle(genv::event ev);
    inline int value() {return _num;}
    inline void setvalue(int neu) {_num=neu;}
};

#endif // COUNTER_HPP_INCLUDED
