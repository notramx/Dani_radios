#ifndef TEXTEDITOR_HPP_INCLUDED
#define TEXTEDITOR_HPP_INCLUDED
#include <string>
#include "widgets.hpp"
#include "window.hpp"

class TextEditor : public Widget{
    std::string _s;
    bool _ticknum;
    int _tick;
public:
    TextEditor(int x, int y, int sx, int sy, std::string s, std::vector<Widget::elem>& vs);
    //TextEditor(int x, int y, int sx, int sy, char c);
    virtual bool focusable() const {return true;}
    virtual void draw();
    virtual void handle(genv::event ev);
    virtual void setrgb(int r, int g, int b);
    virtual void _inctick();
    inline std::string value() {return _s;}
    void setstring(std::string s) {_s=s;}
};



#endif // TEXTEDITOR_HPP_INCLUDED
