#include <bits/stdc++.h>
using namespace std;

// slide window
int lengthOfLongestSubstr(const string &s) {
  int ans = 0;
  unordered_set<char> occ;

  //right edge of sliding window
  int rk = 0;
  for (int i = 0; i < s.size(); i++) {
    if (i) {
      occ.erase(s[i-1]);
    }

    while (rk < s.size() && !occ.count(s[rk])) {
      occ.emplace(s[rk]);
      rk++;
    }

    ans = max(ans, rk - i);
  }

  return ans;
}

int main() {
  string s;
  while (cin>>s){
    cout << lengthOfLongestSubstr(s) << endl;
  }
  return 0;
}
