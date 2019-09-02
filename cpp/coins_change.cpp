//coins中查找和是n的个数
#include <vector>
#include <iostream>
using namespace std;
int change(int n, const vector<int> &coins)
{
    vector<int> d(n+1,0);
    d[0] = 1;
    vector<vector<vector<int>>> v(n+1); 
    for (auto i: coins)
    {
        for (int j = i; j <= n; j++)
        {
            d[j] += d[j - i] ;
            if (v[j-i].empty())
            {
                vector<int> m;
                m.push_back(i);
                v[j].push_back(m);
            }
            else
            {
                for (auto &k:v[j-i])
                {
                    vector<int> m = k;
                    m.push_back(i);
                    v[j].push_back(m);    
                }
            }
        }
    }

    for (auto &i :v[n])
    {
        for (auto &j: i)
            cout << j << " ";
        cout << endl;
    }
    
    for (auto &i :d)
    {
        cout << i << " ";
    }
    cout << endl;

    return d[n];
}

int main()
{
    int r = change(5, {1,2,3});    
    cout << r << endl;
    return 0;
}
