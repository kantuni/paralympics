// TLE
#include <bits/stdc++.h>
using namespace std;

int n, k, l, ans;
vector<vector<int>> g;
vector<int> bits;

int ones(int num) {
  int cnt = 0;
  while (num > 0) {
    cnt += num % 2;
    num >>= 1;
  }
  return cnt;
}

void dfs(int u, int pu, int bu) {
  ans += ones(bu) >= l;
  for (auto v: g[u]) {
    if (v != pu) {
      dfs(v, u, bu | bits[v]);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> k >> l;
  g.resize(n);
  bits.resize(n);
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < s.size(); j++) {
      if (s[j] == '1') {
        bits[i] |= (1 << j);
      }
    }
  }
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int u = 0; u < n; u++) {
    dfs(u, -1, bits[u]);
  }
  for (int u = 0; u < n; u++) {
    ans += ones(bits[u]) >= l;
  }
  cout << ans / 2 << endl;
  return 0;
}
