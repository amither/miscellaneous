#include <bits/stdc++.h>
using namespace std;
vector<int> f(const string &s, const vector<string> &words) {
  vector<int> ret;
  if (s.empty() or words.empty()) return ret;

  //count every word of words
  unordered_map<string, int> cww;
  for (const auto &word: words) {
    cww[word]++;
  }

  unordered_map<string, int> cur_cww;
  int step = words[0].length();
  for (int i = 0; i < step; i++) {
    int left = i;
    int right = i;
    int cnt = 0;
    
    while(right + step < s.length()) {
      cnt++;
      string sub_str = s.substr(right,step);
      right += step;
      cur_cww[sub_str]++;

      while (cur_cww[sub_str] > cww[sub_str]) {
        string sub_str_left = s.substr(left, step);
        cur_cww[sub_str_left]--;;
        cnt--;
        left += step;
      }

      if (cnt == words.size()) ret.push_back(left);
    }
  }

  return ret;

}

int main() {
  string s;
  cin >> s;
  vector<string> words;
  string words_str;
  getline(cin, words_str);
  string word;
  istringstream iss(words_str);
  while (iss >> word) words.emplace_back(word);
  
  vector<int> result;
  result = f(s, words);
  for (auto i : result) cout << i << " ";
  cout << endl;
}