#ifndef WINDOW_HPP_INCLUDED
#define WINDOW_HPP_INCLUDED

#include "widgets.hpp"
#include <vector>


class Window {
protected:
    std::vector<Widget*> vw;
    std::vector<Widget*> vw2;
    int szdb1=0;
    int szdb2=0;
    int szdb3=0;
    std::vector<Widget::elem> vs;
public:
    void esemeny(std::string mitortent);

    void event_loop() ;
};



#endif // WINDOW_HPP_INCLUDED
