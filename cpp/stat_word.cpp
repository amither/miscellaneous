#include <cstdio>
#include <string>
#include <map>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <future>
#include <iostream>
#include <numeric>
using namespace std;

using WordCountMapType = map<string, int>;

WordCountMapType count_file(const string &file)
{
    WordCountMapType result;
    ifstream ifs(file.c_str());
    string word;
    while (ifs >> word)
    {
        result[word]++;   
    }
    return result;
}

template <typename MapIt>
void showCommonWords(MapIt begin, MapIt end, size_t n)
{
    #if 0
    vector<MapIt> vecCount;
    vecCount.reserve(distance(begin, end));
    for (auto i = begin; i != end; i++) vecCount.push_back(i);
    #else
    vector<MapIt> vecCount(distance(begin, end));
    iota(vecCount.begin(), vecCount.end(), begin);
    
    #endif
    
    auto iEnd = vecCount.begin() + n  ;
    partial_sort(vecCount.begin(), iEnd, vecCount.end(), [](WordCountMapType::iterator v1, WordCountMapType::iterator v2)
            {return v1->second > v2->second;});
    
    for (int i= 0; i < n; i++)
    {
        printf("%s\t%d\n", vecCount[i]->first.c_str(), vecCount[i]->second);
    }
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        return -1;
    }
    vector<future<WordCountMapType>> futures; 

    for (int i = 1; i < argc; i++)
    {
        futures.push_back(async([=]{return count_file(argv[i]);}));
    }

    WordCountMapType wordCount;
    for (auto &f: futures)
    {
        auto result = f.get();
        for (auto &i : result)
        {
            wordCount[i.first] += i.second;
        }
    }

    showCommonWords(wordCount.begin(), wordCount.end(), min((size_t)10, wordCount.size()));
    string w;
    cin >> w;
    return 0;

}
