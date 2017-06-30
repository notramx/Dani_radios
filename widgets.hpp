#ifndef WIDGETS_HPP_INCLUDED
#define WIDGETS_HPP_INCLUDED

#include "graphics.hpp"
#include <vector>

class Widget {
protected:
    bool _focused;
    int _x, _y, _size_x, _size_y, _min, _max, _defnum;
    char _c;
    int _r,_g,_b;
public:
    struct elem{
        int ora=0;
        int perc=0;
        int hosszo=0;
        int hosszp=0;
        std::string s="";
    };
    int _num;
    virtual bool is_selected(int mouse_x, int mouse_y) const;

    Widget(int x, int y, int sx, int sy); ///checkbox widget
    Widget(int x, int y, int sx, int sy, int num, int mi, int ma); ///counter widget
    virtual bool _mouse_over(int mouse_x, int mouse_y) const; ///mouse click on _size_x*_size_y field
    virtual bool _mouse_over2(int mouse_x, int mouse_y) const; ///reduced by a square on right side
    virtual int _mouse_over3(int mouse_x, int mouse_y, int db) const; ///reduced to a square on right side
    virtual bool _increase(int mouse_x, int mouse_y) const; ///mouse click on increase sign
    virtual bool _decrease(int mouse_x, int mouse_y) const; ///mouse click on decrease sign
    virtual bool _open(int mouse_x, int mouse_y) const; ///reduced to a square on right side
    virtual int _select(int mouse_x, int mouse_y, int db) const; ///returns which item has been selected
    virtual void draw();
    virtual void write() const;
    virtual void handle(genv::event ev);
    virtual bool focusable() const;
    virtual void focus();
    virtual void unfocus();
    virtual void _inctick();
    inline char value() {return _c;}
    virtual void setrgb(int r, int g, int b);
    void setchar(char c) {_c=c;}
    void reset() {_num=_defnum;}
};


#endif // WIDGETS_HPP_INCLUDED
