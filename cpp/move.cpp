#include <string>
#include <iostream>
using namespace std;
class A 
{
public:
    A(const string &a): c(a){};
    A(A &&a)
    {
        c = std::move(a.c);
    };
    A& operator=(A &&a)
    {
        c = std::move(a.c);
        return *this;
    };
public:
    string c;
};

int main()
{
    A a("123");
    cout << a.c << endl;
    A b(A("234"));
    cout << a.c << endl;
    cout << b.c << endl;
    b = move(a);
    cout << a.c << endl;
    cout << b.c << endl;
    return 0;
}
