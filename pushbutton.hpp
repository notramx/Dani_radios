#ifndef PUSHBUTTON_HPP_INCLUDED
#define PUSHBUTTON_HPP_INCLUDED

#include "widgets.hpp"
#include "window.hpp"

class PushButton : public Widget {
    Window * _parent;
    std::string _felirat;
public:
    std::string _azonosito;
    PushButton(Window * parent, int x, int y, int sx,
                int sy, std::string s, std::string azonosito);
    PushButton(int x, int y, int sx,
                int sy, std::string s, std::string azonostito);
    virtual void draw();
    virtual void handle(genv::event ev);
    virtual void action();
};

#endif // PUSHBUTTON_HPP_INCLUDED
