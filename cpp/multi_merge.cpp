//多路归并有序数组
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <random>
using namespace std;

struct M {
    int value;
    int which;
    int index;
};
using my_container_t  = vector<M>;

vector<int> f(const vector<vector<int>> &v) {
    vector<int> r;
    if (v.size() == 0)
        return r;
    
    auto my_comp = [](const M &m1, const M &m2){return m1.value > m2.value;};
    priority_queue<M, my_container_t, decltype(my_comp)> q(my_comp);

    for (int i = 0; i < v.size(); i++) {
        if (v[i].size() > 0) {
            q.push(M{v[i][0], i, 0});
        }
    }

    while (!q.empty()) {
        const auto &p = q.top();
        r.push_back(p.value);
        
        if (v[p.which].size() > p.index+1) {
            q.push(M{v[p.which][p.index+1], p.which, p.index+1});
        }
        q.pop();
        
    }

    for_each(r.begin(), r.end(), [](const int &i){cout << i << " ";});
    cout << endl;
    
    return r;
}

void print(const vector<vector<int>> &v)
{
    for_each(v.begin(), v.end(), [](const vector<int> &m){
        for_each(m.begin(), m.end(), [](const int &j){cout << j << " ";});
        cout << endl;
    });
}

int main()
{
    vector<vector<int>> v;
    auto ran = std::mt19937{std::random_device{}()};
    for (int i = 0; i < 3; i++) {
        
        vector<int> m(ran()%10+1);

        std::iota(m.begin(), m.end(), ran()%1000);
        //generate(m.begin(), m.end(), [n=ran()%1000]()mutable{return n++;});
        v.push_back(move(m));
    }
    v.push_back(vector<int>());
    print(v); 
    f(v);

}
