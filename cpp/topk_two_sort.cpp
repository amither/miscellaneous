#include <iostream>
#include <vector>
using namespace std;

int f(vector<int> &vec1, vector<int> &vec2, int i, int j, int k)
{
    int size1 = vec1.size() - i;
    int size2 = vec2.size() - j;
    
    if (size1 + size2 < k)
        return 0;

    if (size2 == 0)
        return vec2[i + k -1];

	if (k==1)
    {
        return min(vec1[i], vec2[j]);
    }

    if (size1 < size2)
        return f(vec2, vec1, j, i, k);

    int q = min(k/2, size2);
    int p = k - q;
    if (vec1[i + p-1] == vec2[j + q-1])
    {
        return vec1[i+p-1];
    }
    else if (vec1[i+p-1] > vec2[j+q-1])
    {
        return  f(vec1, vec2, i, j+q, k-q);
    }
    else
        return f(vec1, vec2, i+p, j, k-p);
		
}

int main()
{
    vector<int> vec1 = {1, 2,6, 9, 100};
    vector<int> vec2 = {3, 5, 7,8, 9, 10};
    
    cout << f(vec1, vec2, 0, 0, 1)<< endl;
    return 0;
    
}
