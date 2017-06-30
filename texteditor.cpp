#include "texteditor.hpp"
#include "window.hpp"
#include <string>
using namespace std;
using namespace genv;

TextEditor::TextEditor(int x, int y, int sx, int sy, string s, vector<Widget::elem>& vs) : Widget(x,y,sx,sy) {_s=s; _r=0; _g=0; _b=0;}
//TextEditor::TextEditor(int x, int y, int sx, int sy, char c) : Widget(x,y,sx,sy) {_c=c; _r=255; _g=255; _b=255; _tick=0;}

void TextEditor::draw() {
    gout << color(155,155,155);
    gout << move_to(_x, _y) << box(_size_x, _size_y);
    gout << color(0,0,0) << move_to(_x+1, _y+1) << box(_size_x-2, _size_y-2);
    gout << move_to(_x+10,_y+2*_size_y/3) << color(255,255,255);
   /* if (!_focused && _s=="")
        gout << text("hostname");
    else*/ gout << text(_s);
    if (_focused) gout << text("|");
}

void TextEditor::setrgb(int r, int g, int b)
{
    _r=r;
    _g=g;
    _b=b;
}

void TextEditor::handle(event ev) {
   if(ev.type==ev_key && ev.keycode>0)
    {
        char c=ev.keycode;
        string sh=_s+c+'|';
        if(gout.twidth(sh)<_size_x-_size_y)
        {
            _s+=c;
        }
    }

    if(ev.type==ev_key && ev.keycode==key_backspace)
    {
        if (_s.size()>0)
            _s.erase(_s.size()-1);
        if (_s.size()>0)
            _s.erase(_s.size()-1);
    }
}

void TextEditor::_inctick() {
    _tick++;
}
