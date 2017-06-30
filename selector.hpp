#ifndef SELECTOR_HPP_INCLUDED
#define SELECTOR_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"
#include "window.hpp"
#include <vector>

class Selector : public Widget {
protected:
    bool _checked;
    int _selected, _start, _items;
    bool _checked2, _nyit;
    std::string _s;
    std::vector<Widget::elem> _vs;
public:
    Selector(int x, int y, int sx, int sy, std::vector<Widget::elem> vs);
    virtual void draw();
    virtual void handle(genv::event ev);
    virtual void setvs(std::vector<Widget::elem> vs);
    virtual int getsto(int i);
    virtual int getendo(int i);
    virtual int getstp(int i);
    virtual int getendp(int i);
    virtual int getlen(int i);
    inline int getvssize() {return _vs.size();}
};

#endif // SELECTOR_HPP_INCLUDED
