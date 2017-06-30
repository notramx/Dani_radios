#include "selector.hpp"
#include "graphics.hpp"
#include "window.hpp"
#include <vector>

using namespace genv;
using namespace std;

Selector::Selector(int x, int y, int sx, int sy, vector<Widget::elem> vs)
    : Widget(x,y,sx,sy)
{
    _checked=false;
    _checked2=false;
    _selected=0;
    _s="";
    _start=0;
    _nyit=true;
    _vs=vs;
    if(_vs.size()<4) _items=_vs.size();
            else _items=4;
}

void Selector::draw()
{
        if(_vs.size()<4) _items=_vs.size();
            else _items=4;

        gout << move_to(_x,_y) << color(255,255,255) << box(_size_x,_size_y*4);
        gout << move_to(_x+2,_y+2) << color(0,0,0) << box(_size_x-4,_size_y*4-4);

        for(int i=0; i<_items; i++)
        {
            gout << move_to(_x,_y+i*_size_y) << color(255,255,255) << box(_size_x, _size_y);
            gout << move_to(_x+2,_y+i*_size_y+2) << color(0,0,0) << box(_size_x-4, _size_y-4);
            gout << move_to(_x+4,_y+i*_size_y+2*_size_y/3) << color(255,255,255) << text(_vs[_start+i].s);
            gout << move_to(_x+_size_x-_size_y,_y+i*_size_y) << color(255,255,255) << box(_size_y,_size_y);
            gout << move_to(_x+_size_x-_size_y+2,_y+i*_size_y+2) << color (0,0,0) << box(_size_y-4,_size_y-4);
        }
        if(_vs.size()>4)
        {
            gout << move_to(_x+_size_x-_size_y,_y+_items*_size_y) << genv::move(_size_y/2, -_size_y/4) << color(255,255,255) << line(-_size_y/4,-_size_y/2) << line(_size_y/2,0) << line(-_size_y/4,_size_y/2);
            gout << move_to(_x+_size_x-_size_y,_y) << genv::move(_size_y/2, _size_y/4) << color(255,255,255) << line(-_size_y/4,_size_y/2) << line(_size_y/2,0) << line(-_size_y/4,-_size_y/2);
        }
}

void Selector::setvs(std::vector<Widget::elem> vs)
{
    if(_vs.size()>0)
    {
        int hely=0;
        bool ora=false;
        while(_vs[hely].ora<=vs[vs.size()-1].ora)
        {
            hely++;
            ora=true;
        }

        while(_vs[hely].perc<=vs[vs.size()-1].perc && ora)
            hely++;

        _vs.resize(_vs.size()+1);
        _vs[_vs.size()-1].ora=vs[vs.size()-1].ora;
        _vs[_vs.size()-1].perc=vs[vs.size()-1].perc;
        _vs[_vs.size()-1].hosszo=vs[vs.size()-1].hosszo;
        _vs[_vs.size()-1].hosszp=vs[vs.size()-1].hosszp;
        _vs[_vs.size()-1].s=vs[vs.size()-1].s;

        for(int i=_vs.size()-1; i>hely; i--)
            {
                Widget::elem seged;
                seged.ora=_vs[i-1].ora;
                seged.perc=_vs[i-1].perc;
                seged.hosszo=_vs[i-1].hosszo;
                seged.hosszp=_vs[i-1].hosszp;
                seged.s=_vs[i-1].s;

                _vs[i-1].ora=_vs[i].ora;
                _vs[i-1].perc=_vs[i].perc;
                _vs[i-1].hosszo=_vs[i].hosszo;
                _vs[i-1].hosszp=_vs[i].hosszp;
                _vs[i-1].s=_vs[i].s;

                _vs[i].ora=seged.ora;
                _vs[i].perc=seged.perc;
                _vs[i].hosszo=seged.hosszo;
                _vs[i].hosszp=seged.hosszp;
                _vs[i].s=seged.s;
            }
    }
    else
    {
        _vs.resize(1);
        _vs[_vs.size()-1].ora=vs[vs.size()-1].ora;
        _vs[_vs.size()-1].perc=vs[vs.size()-1].perc;
        _vs[_vs.size()-1].hosszo=vs[vs.size()-1].hosszo;
        _vs[_vs.size()-1].hosszp=vs[vs.size()-1].hosszp;
        _vs[_vs.size()-1].s=vs[vs.size()-1].s;
    }
}

void Selector::handle(event ev)
{
    if (ev.type == ev_mouse && _nyit==true && ev.button==btn_left) {
        if(_mouse_over3(ev.pos_x, ev.pos_y, _items)==1 && _start>0)
            _start--;
        if(_mouse_over3(ev.pos_x, ev.pos_y, _items)==2 && _start<_vs.size()-_items)
            _start++;
    }

    if(_vs.size()<4) _items=_vs.size();
        else _items=4;
}

int Selector::getsto(int i) {
    return _vs[i].ora;
}

int Selector::getstp(int i) {
    return _vs[i].perc;
}

int Selector::getendo(int i) {
    return _vs[i].ora + _vs[i].hosszo;
}

int Selector::getendp(int i) {
    return _vs[i].perc + _vs[i].hosszp;
}

int Selector::getlen(int i) {
    return _vs[i].hosszo * 60 + _vs[i].hosszp;
}
