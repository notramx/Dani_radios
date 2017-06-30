#include "statictext.hpp"
#include <string>
using namespace std;
using namespace genv;
/*StaticText::StaticText(int x, int y, int sx, int sy, string s) : Widget(x,y,sx,sy) {
    _s=s;
}*/
StaticText::StaticText(int x, int y, int sx, int sy, char c) : Widget(x,y,sx,sy) {
    _c=c;
    _r=255;
    _g=255;
    _b=255;
}

void StaticText::setrgb(int r, int g, int b)
{
    _r=r;
    _g=g;
    _b=b;
}

void StaticText::draw() {
    gout << color(255,255,255) << move_to(_x, _y) << box(_size_x, _size_y);
    gout << color(0,0,0) << move_to(_x+2, _y+2) << box(_size_x-4, _size_y-4) << color(255,255,255);
    gout << move_to(_x+10,_y+2*_size_y/3) << color(_r,_g,_b) << text(_c);
}
