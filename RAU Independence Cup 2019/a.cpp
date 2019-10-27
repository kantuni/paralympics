// TLE
#include <bits/stdc++.h>
#define INF (long long) 1e18
using namespace std;

long long cost(vector<long long> a, int ti) {
  long long c = 0;
  for (int i = 1; i < ti; i++) {
    long long diff = a[i - 1] - a[i];
    if (diff >= 0) {
      a[i] += diff + 1;
      c += diff + 1;
    }
  }
  for (int i = a.size() - 2; i > ti; i--) {
    long long diff = a[i + 1] - a[i];
    if (diff >= 0) {
      a[i] += diff + 1;
      c += diff + 1;
    }
  }
  long long l = ti > 0 ? a[ti - 1] : 0;
  long long r = ti < a.size() - 1 ? a[ti + 1] : 0;
  long mxlr = max(l, r);
  long long diff = mxlr - a[ti];
  if (diff >= 0) {
    a[ti] += diff + 1;
    c += diff + 1;
  }
  return c;
}

int main() {
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long ans = INF;
  for (int i = 0; i < n; i++) {
    ans = min(ans, cost(a, i));
  }
  cout << ans << endl;
  return 0;
}
