#include <iostream>
#include <vector>
#include "singleton.h"
#include <future>
using namespace std;

class C 
{
public:
    C() {cout << "construct"<< endl; a = new int(0); }
    ~C() {delete a;}
    C(const C &c) {cout << "copy construct"<< endl; a = new int(0); *a = *(c.a);}
    C(C&& c) {cout << "move construct" << endl; a = c.a; c.a = nullptr;}

    int *a;
};

C g()
{
    C c;
    return c;
}
void f(C &&c)
{
    vector<C> v;
    v.push_back(move(c));
    cout << "f" << endl;
}

void f(const C &c)
{
    cout << "c" << endl;
}
int main()
{
    /*
    C c;
    C &d = c;
    f(d);
    f(move(c));
    f(g());
    */

    cout << "singleton" << endl;
    auto e = async([=]{cout << "thread e"<< endl;C *e = singleton<C>::get(); return e;});
    auto g = async([=]{cout << "thread g"<< endl;C *e = singleton<C>::get(); return e;});
    e.get();
    g.get();
    

    return 0;
}
