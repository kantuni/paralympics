#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, p;
  cin >> n >> p;
  vector<int> a(n);
  map<int, int> cnt;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  priority_queue<pair<int, int>> pq;
  for (auto kv: cnt) {
    pq.push({kv.second, kv.first});
  }
  int ans = 0;
  while (pq.size() >= p) {
    vector<pair<int, int>> tmp;
    for (int i = 0; i < p; i++) {
      auto top = pq.top(); pq.pop();
      if (top.first > 1) {
        tmp.push_back({top.first - 1, top.second});
      }
    }
    for (int i = 0; i < tmp.size(); i++) {
      pq.push(tmp[i]);
    }
    ans++;
  }
  cout << ans << endl;
  return 0;
}
