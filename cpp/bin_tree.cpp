//二叉树的遍历，递归和非递归实现
#include <iostream>
#include <stack>
using namespace std;
struct T {
    int v;
    struct T *l;
    struct T *r;
    
    T(int m): v(m), l(0), r(0) {};
};

struct T * build()
{
    struct T *t = new T(1);
    t->l = new T(2);
    t->r = new T(7);
    t->l->l = new T(3);
    t->l->r = new T{6};
    t->l->l->l = new T(4);
    t->l->l->r = new T{5};
    t->r->l = new T(8);
    t->r->r = new T(9);
    return t;
}

void walk_front_recur(struct T *t)
{
    if (!t) return;
    
    cout << t->v << " ";
    walk_front_recur(t->l);
    walk_front_recur(t->r);
}
void walk_middle_recur(struct T *t)
{
    if (!t) return;
    
    walk_middle_recur(t->l);
    cout << t->v << " ";
    walk_middle_recur(t->r);
}

void walk_front(struct T *t)
{
    stack<T*> s;
    s.push(t);
    while (!s.empty()) {
        T * t1 = s.top();
        s.pop();
        while(t1)
        {
            cout << t1->v << " ";
            s.push(t1->r);
            t1 = t1->l;
        }
        
    }
}

void walk_middle(struct T *t)
{
    stack<T*> s;
    while(t) 
    {
        s.push(t);
        t = t->l;
    }

    while(!s.empty()) 
    {
        T *t1 = s.top();
        s.pop();
        cout << t1->v << " ";
        T *t2 = t1->r;
        while (t2)
        {
            s.push(t2);
            t2 = t2->l;
        }
        
    }
}

int main()
{
    struct T *t = build();
    cout << "--front--" << endl;
    walk_front_recur(t);
    cout << endl;
    walk_front(t);
    cout << endl;
    cout << "--middle--" << endl;
    walk_middle_recur(t);
    cout << endl;
    walk_middle(t);
    cout << endl;
    return 0;
}
