#include "graphics.hpp"
#include "counter.hpp"
#include "selector.hpp"
#include "widgets.hpp"
#include "texteditor.hpp"
#include "statictext.hpp"
#include "window.hpp"
#include "pushbutton.hpp"
#include <vector>

using namespace std;
using namespace genv;

class ValamiButton;

class MyWindow : public Window {
public:
    Counter *Counto;
    Counter *Countp;
    Counter *Counth;
    ValamiButton *vButton;
    ValamiButton *vButtonny;
    ValamiButton *vButtonsz;
    Selector *Select;
    TextEditor *te;
    MyWindow();

    void valami()
    {
        int ho=0;
        int hp=0;
        Counth->setvalue(Counth->value()+Countp->value());
        bool ov=false;
        if(Countp->value()>59)
            ov=true;
        while(Counth->value()-60>=0)
        {
            ho+=1;
            Counth->setvalue(Counth->value()-60);
        }
        Widget::elem ns;
        ns.ora=Counto->value();
        ns.perc=Countp->value();
        ns.hosszo=ho;
        ns.hosszp=hp;
        ns.s=te->value();
        bool neu=true;
        for (int i=0; i<Select->getvssize(); i++)
            {
                if(ns.ora>=Select->getsto(i) && ns.ora<=Select->getendo(i))
                    if(!ov)
                        if(ns.perc>=Select->getstp(i) && ns.perc<=Select->getendp(i))
                            neu=false;
                    else
                    {
                        if(ns.perc>=Select->getstp(i))
                            neu=false;
                        int hossz=ns.perc+ns.hosszp;
                        while(hossz>=60)
                            hossz-=60;
                        if(hossz<=Select->getendp(i))
                            neu=false;
                    }
                if(ns.ora+ns.hosszo>=Select->getsto(i) && ns.ora+ns.hosszo<=Select->getendo(i))
                    if(ns.perc+ns.hosszp>=Select->getstp(i) && ns.perc+ns.hosszp<=Select->getendp(i))
                        neu=false;
            }

        if(neu)
        {
            vs.push_back(ns);
            Select->setvs(vs);
        }

        te->setstring("");
        Counto->setvalue(12);
        Countp->setvalue(30);
        Counth->setvalue(40);
    }
};

class ValamiButton : public PushButton {
    MyWindow *mywparent;
public:
    ValamiButton(MyWindow *parent, int x, int y, int sx, int sy, std::string s, std::string azonosito)
    :PushButton(parent, x, y, sx, sy, s, azonosito)
    {
        mywparent=parent;
    }

    virtual void action();
};

MyWindow::MyWindow() {
    Counto = new Counter(120,10,100,40,12,0,23,true);
    vw.push_back(Counto);
    Countp = new Counter(230,10,100,40,30,0,59,true);
    vw.push_back(Countp);
    Counth = new Counter(10,70,100,40,40,1,300,false);
    vw.push_back(Counth);
    Select = new Selector(10,150,150,40,vs); /// statictext
    vw.push_back(Select);
    te = new TextEditor(10,10,100,40,"példa",vs);
    vw.push_back(te);
    vButton = new ValamiButton(this, 10, 350, 100, 40, "hozzaad", "new");
    vButtonny = new ValamiButton(this, 150, 350, 100, 40, "hozzaad", "mod");
    vButtonsz = new ValamiButton(this, 290, 350, 100, 40, "szerkeszt", "new");
    vw.push_back(vButton);
    vw.push_back(vButtonny);
    vw.push_back(vButtonsz);
}

void ValamiButton::action()
{
    if(_azonosito=="new")
        mywparent->valami();
    /*if(_azonosito=="mod")
        mywparent->valami2();*/
}

int main()
{
    gout.open(400,400);
    MyWindow *mywindow = new MyWindow;
    mywindow->event_loop();
    return 0;
}
