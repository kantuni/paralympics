#include <bits/stdc++.h>
#define K 8
using namespace std;

int n, k, l, ans;
vector<vector<int>> g;
vector<bitset<K>> bits;
vector<int> color;
map<int, long long> above, exact;

long long dfs(int u) {
  color[u] = 2;
  long long cc = 1;
  for (auto v: g[u]) {
    if (color[v] == 0) {
      cc += dfs(v);
    }
  }
  return cc;
}

set<int> saturate(set<int> s) {
  set<int> nxt;
  for (auto num: s) {
    bitset<K> bnum(num);
    for (int i = 0; i < k; i++) {
      if (bnum[i] == 0) {
        auto tmp = bnum;
        tmp[i] = 1;
        nxt.insert(tmp.to_ulong());
      }
    }
  }
  return nxt;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> k >> l;
  g.resize(n);
  bits.resize(n);
  color.resize(n);
  for (int u = 0; u < n; u++) {
    string s;
    cin >> s;
    for (int i = 0; i < k; i++) {
      bits[u][k - i - 1] = s[i] - '0';
    }
  }
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int m = 0; m < pow(2, k); m++) {
    fill(color.begin(), color.end(), 0);
    int mi = pow(2, k) - 1 - m;
    bitset<K> bmi(mi);
    bmi.flip();
    for (int u = 0; u < n; u++) {
      for (int i = 0; i < k; i++) {
        if (bmi[k - i - 1] == 1 and bits[u][k - i - 1] == 1) {
          color[u] = 1;
        }
      }
    }
    long long paths = 0;
    for (int u = 0; u < n; u++) {
      if (color[u] == 0) {
        long long cc = dfs(u);
        paths += cc * (cc - 1) / 2;
      }
    }
    above[m] = paths;
  }
  for (int m = 0; m < pow(2, k); m++) {
    int mi = pow(2, k) - 1 - m;
    exact[m] = above[mi];
    set<int> mis = {mi};
    set<int> nxt = saturate(mis);
    int i = 1;
    while (!nxt.empty()) {
      for (auto num: nxt) {
        exact[m] += pow(-1, i % 2) * above[num];
      }
      nxt = saturate(nxt);
      i++;
    }
  }
  long long ans = 0;
  for (int m = 0; m < pow(2, k); m++) {
    bitset<K> b(m);
    if (b.count() >= l) {
      ans += exact[m];
    }
  }
  for (int u = 0; u < n; u++) {
    if (bits[u].count() >= l) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
