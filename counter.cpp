#include "counter.hpp"
#include "graphics.hpp"
#include "window.hpp"
#include <sstream>

using namespace genv;
using namespace std;

Counter::Counter(int x, int y, int sx, int sy, int num, int mi, int ma, bool ford)
    : Widget(x,y,sx,sy,num,mi,ma)
{
    _ford=ford;
}

void Counter::draw()
{
    gout << move_to(_x, _y) << color(255,255,255) << box(_size_x, _size_y);
    gout << move_to(_x+2, _y+2) << color(0,0,0) << box(_size_x-4, _size_y-4);
    gout << move_to(_x+_size_x-_size_y/2, _y) << color(255,255,255) << box(_size_y/2, _size_y/2);
    gout << move_to(_x+_size_x-_size_y/2+2, _y+2) << color(0,0,0) << box(_size_y/2-4, _size_y/2-4);
    gout << move_to(_x+_size_x-_size_y/2, _y+_size_y/2) << color(255,255,255) << box(_size_y/2, _size_y/2);
    gout << move_to(_x+_size_x-_size_y/2+2, _y+_size_y/2+2) << color(0,0,0) << box(_size_y/2-4, _size_y/2-4);
    gout << move_to(_x+_size_x-_size_y/2,_y) << color(255,255,255) << genv::move(_size_y/4,_size_y/8) << line(-_size_y/8,_size_y/4) << line(_size_y/4,0) << line(-_size_y/8,-_size_y/4);
    gout << move_to(_x+_size_x-_size_y/2,_y+_size_y) << genv::move(_size_y/4,-_size_y/8) << line(-_size_y/8,-_size_y/4) << line (_size_y/4,0) << line(-_size_y/8, _size_y/4);
    stringstream ss;
    ss << _num;
    gout << move_to(_x+4,_y+2*_size_y/3) << color(255,255,255) << text(ss.str());
}

void Counter::write() const
{
    stringstream ss;
    ss << _num;
    gout << move_to(_x+4,_y+2*_size_y/3) << color(255,255,255) << text(ss.str());
}

void Counter::handle(event ev)
{
    if(_ford)
    {
        if(_increase(ev.pos_x, ev.pos_y) && ev.button>0)
    {
        _num++;
        if(_num>_max)
            _num-=(_max+1);
    }

    if(_decrease(ev.pos_x, ev.pos_y) && ev.button>0)
    {
        _num--;
        if(_num<_min)
            _num+=(_max+1);
    }

    if(ev.keycode==key_up)
    {
        _num++;
        if(_num>_max)
            _num-=(_max+1);
    }

    if(ev.keycode==key_down)
    {
        _num--;
        if(_num<_min)
            _num+=(_max+1);
    }

    if(ev.keycode==key_pgup)
    {
        _num+=10;
        if(_num>_max)
            _num-=(_max+1);
    }

    if(ev.keycode==key_pgdn)
    {
        _num-=10;
        if(_num<_min)
            _num+=(_max+1);
    }

    }
    else
    {
    if(_increase(ev.pos_x, ev.pos_y) && ev.button>0 && _num<_max)
    {
        _num++;
    }

    if(_decrease(ev.pos_x, ev.pos_y) && ev.button>0 && _num>_min)
    {
        _num--;
    }

    if(ev.keycode==key_up && _num<_max)
    {
        _num++;
    }

    if(ev.keycode==key_down && _num>_min)
    {
        _num--;
    }

    if(ev.keycode==key_pgup && _num<_max-10)
    {
        _num+=10;
    }

    if(ev.keycode==key_pgdn && _num>_min+10)
    {
        _num-=10;
    }
    }

}
