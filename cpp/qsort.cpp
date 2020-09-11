#include <bits/stdc++.h>
using namespace std;
void qsort(vector<int>& values, int l, int r) {
  if (values.size() == 0) return;
  if (l >= r) return;

  default_random_engine random_engine;
  uniform_int_distribution<int> dist(l, r);

  int m = dist(random_engine);
  swap(values[m], values[l]);
  m = l;
  for (int i = l + 1; i <= r; i++) {
    if (values[i] < values[l]) swap(values[++m], values[i]);
  }

  swap(values[m], values[l]);

  qsort(values, l, m - 1);
  qsort(values, m + 1, r);
}

int main() {
  vector<int> values;
  auto now = chrono::system_clock::now(); 
  
  default_random_engine random_engine(now.time_since_epoch().count());
  uniform_int_distribution<int> dist(0, 20);
  for (int i = 0; i < 10; i++) values.push_back(dist(random_engine));

  qsort(values, 0, values.size());

  for (auto& v : values) cout << v << " ";
  cout << endl;
  return 0;
}