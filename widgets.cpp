#include "widgets.hpp"
#include "graphics.hpp"
#include <vector>
#include <iostream>

using namespace genv;
using namespace std;

Widget::Widget(int x, int y, int sx, int sy)
{
    _x=x;
    _y=y;
    _size_x = sx;
    _size_y=sy;
    _num=-1;
    _min=0;
    _max=0;
    _defnum=_num;
    _focused=false;
}

Widget::Widget(int x, int y, int sx, int sy, int num, int mi, int ma) ///counter widget
{
    _x=x;
    _y=y;
    _size_x=sx;
    _size_y=sy;
    _num=num;
    _min=mi;
    _max=ma;
    _defnum=_num;
}

bool Widget::_mouse_over(int mouse_x, int mouse_y) const ///mouse click on _size_x*_size_y field
{
    return mouse_x>_x && mouse_x<_x+_size_x && mouse_y>_y && mouse_y<_y+_size_y;
}

bool Widget::_mouse_over2(int mouse_x, int mouse_y) const ///reduced by a square on right side
{
    return mouse_x>_x && mouse_x<_x+_size_x-_size_y && mouse_y>_y && mouse_y<_y+_size_y;
}

int Widget::_mouse_over3(int mouse_x, int mouse_y, int db) const ///reduced to a square on right side
{
    if(mouse_x>_x+_size_x-_size_y && mouse_x<_x+_size_x && mouse_y>_y && mouse_y<_y+_size_y)
        return 1;
    if(mouse_x>_x+_size_x-_size_y && mouse_x<_x+_size_x && mouse_y>_y+3*_size_y && mouse_y<_y+4*_size_y)
        return 2;
}

bool Widget::_increase(int mouse_x, int mouse_y) const ///mouse click on increase sign
{
    return mouse_x>_x+_size_x-_size_y/2 && mouse_x<_x+_size_x && mouse_y>_y && mouse_y<_y+_size_y/2;
}

bool Widget::_decrease(int mouse_x, int mouse_y) const ///mouse click on decrease sign
{
    return mouse_x>_x+_size_x-_size_y/2 && mouse_x<_x+_size_x && mouse_y>_y+_size_y/2 && mouse_y<_y+_size_y;
}

bool Widget::_open(int mouse_x, int mouse_y) const ///mouse click on selector's opening sign
{
    return mouse_x>_x+_size_x-_size_y && mouse_x<_x+_size_x && mouse_y>_y && mouse_y<_y+_size_y;
}

bool Widget::is_selected(int mouse_x, int mouse_y) const
{
    return mouse_x>_x && mouse_x<_x+_size_x && mouse_y>_y && mouse_y<_y+_size_y;
}

int Widget::_select(int mouse_x,int mouse_y,int db) const ///returns which item has been selected
{
    int i=0;
    bool select=false;
    while(i<db&&!select)
    {
        if(_mouse_over2(mouse_x, mouse_y-(i+1)*_size_y))
        {
            select=true;
        }
        i++;
    }
    i--;

    if(select)
        return i;
    else return -1;
}

void Widget::handle(event ev) {
}

bool Widget::focusable() const {return true;}

void Widget::focus() {
    _focused = true;
}

void Widget::unfocus() {
    _focused = false;
}

void Widget::draw() {}

void Widget::write() const {}

void Widget::_inctick() {}

void Widget::setrgb(int r, int g, int b) {_r=r; _g=g; _b=b;}
