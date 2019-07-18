#include <iostream>
using namespace std;

unique_ptr<string> f ()
{
    return unique_ptr<string>{new string("abcd")};
}

int main() {
    auto x = 5;
    auto y = &x;
    cout << x << endl;

    auto p = f();
    cout << *p << endl;
    return 0;
}