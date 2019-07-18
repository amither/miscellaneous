#include <iostream>
#include <vector>
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
    C c;
    C &d = c;
    f(d);
    f(move(c));
    f(g());
    return 0;
}
