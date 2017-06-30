#ifndef STATICTEXT_HPP_INCLUDED
#define STATICTEXT_HPP_INCLUDED
#include <string>
#include "widgets.hpp"

class StaticText : public Widget {
protected:
    std::string _s;
public:
    //StaticText(int x, int y, int sx, int sy, std::string s);
    StaticText(int x, int y, int sx, int sy, char c);
    virtual void setrgb(int r, int g, int b);
    virtual void draw();
    virtual bool focusable() const {return false;}
    inline char value() {return _c;}
    //void setText(std::string s) {_s=s;}
    void setchar(char c) {_c=c;}
};


#endif // STATICTEXT_HPP_INCLUDED
