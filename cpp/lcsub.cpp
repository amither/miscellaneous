#include <string>
#include <vector>
#include <iostream>
using namespace std;
void f(const string &s1, const string &s2)
{
    int maxIndex = 0;
    int maxLength = 0;
    vector<vector<int> > vec(s2.length());
    for (auto &v: vec)
    {
        v.resize(s1.length());
    }

    //填第一行
    for (int i = 0; i < s1.length(); i++)
    {
        if (s2[0] == s1[i])
            vec[0][i] = 1;
        else
            vec[0][i] = 0;
    }

    //填第一列
    for (int i = 0; i < s2.length(); i++)
    {
        if (s1[0] == s2[i])
            vec[i][0] = 1;
        else
            vec[i][0] = 0;
    }

    for (int i = 1; i < s2.length(); i++)
    {
        for (int j = 1; j < s1.length(); j++)
        {
            if (s1[i] == s2[j])
            {
                vec[i][j] = vec[i-1][j-1] + 1;
                if (vec[i][j] > maxLength)
                {
                    maxLength = vec[i][j];
                    maxIndex = i;
                }
            }
            else
                vec[i][j] = 0;
        }
    }

    cout << maxLength << endl;
    cout << s1.substr(maxIndex + 1 - maxLength, maxLength) << endl;
}

int main(int argc, char *argv[])
{
    f(argv[1], argv[2]);
    return 0;
}
