#include <string>
#include <vector>
#include <iostream>
using namespace std;

int max(int i, int j, int k)
{
    int m = i;
    if (j > m)
        m = j;

    if (k > m)
        m = k;

    return m;
}

void print(vector<vector<int> > &vec, int i, int j, string l, string r)
{
    if (i == 0 && vec[i][j] == 1)
    {
        cout << r[0] << " ";
        return;
    }

    if (j == 0 && vec[i][j] == 1)
    {
        cout << l[0] << " ";
        return;
    }

    if (vec[i-1][j-1] + 1 == vec[i][j] && r[i] == l[j])
    {
        print(vec, i-1, j-1, l , r);
        cout << l[j] << " ";
        return;
    }

    if (vec[i-1][j-1]  == vec[i][j])
    {
        print(vec, i-1, j-1, l, r);
        return;
    }

    if (vec[i-1][j]  == vec[i][j])
    {
        print(vec, i-1, j, l, r);
        return;
    }

    if (vec[i][j-1]  == vec[i][j])
    {
        print(vec, i, j-1, l, r);
        return;
    }
}
void lcs(string l, string r)
{
    vector<vector<int> > vec(r.length());
    for (int i = 0; i < vec.size(); i++)
        vec[i].resize(l.length());

    //初始化第一行和第一列
    for (int i = 0; i < l.length(); i++)
    {
        if (r[0] == l[i])
            vec[0][i] = 1; 
        else if (i)
            vec[0][i] = vec[0][i-1];
        else
            vec[0][i] = 0;
    }

    for (int i = 0; i < r.length(); i++)
    {
        if (l[0] == r[i])
            vec[i][0] = 1;
        else if (i)
            vec[i][0] = vec[i-1][0];
        else
            vec[i][0] = 0;
    }
    
    for (int i = 1; i < r.length(); i++)
    {
        for (int j = 1; j < l.length(); j++)
        {
            if (r[i] == l[j])
            {
                vec[i][j] = max(vec[i-1][j-1]+1, vec[i-1][j], vec[i][j-1]);
            }
            else
                vec[i][j] = max(vec[i-1][j-1], vec[i-1][j], vec[i][j-1]);
        }
    }

    for(auto &i : vec)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }

    cout << l << endl;
    cout << r << endl;
    print(vec, r.length()-1, l.length()-1, l, r);
    
}




int main()
{
    string l = "abcdefef";
    string r = "bdfjiefsae";
    lcs(l, r);
}
