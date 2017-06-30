#include "window.hpp"
#include <sstream>
#include <iostream>

using namespace genv;



void Window::event_loop() {
    gin.timer(40);
    event ev;
    int focus = -1;
    while(gin >> ev && ev.keycode!=key_escape) {
        if (ev.type == ev_key && ev.keycode == key_tab) {
            if(focus!=-1) {
                vw[focus]->unfocus();
            }
            do {
                focus++;
                if (focus>=vw.size()) focus =0;
            } while (!vw[focus]->focusable()); //TODO:vegtelenciklus!
            vw[focus]->focus();
        }
        if (ev.type == ev_mouse && ev.button==btn_left) {
            for (size_t i=0;i<vw.size();i++) {
                if (vw[i]->is_selected(ev.pos_x, ev.pos_y) && vw[i]->focusable()) {
                        if (focus!=-1) vw[focus]->unfocus();
                        focus = i;
                        vw[focus]->focus();
                }
            }
        }

        for (size_t i=0;i<vw.size();i++) {
            vw[i]->draw();
        }

        if (focus!=-1) {
            vw[focus]->handle(ev);
        }

        gout << refresh;
    }
}
