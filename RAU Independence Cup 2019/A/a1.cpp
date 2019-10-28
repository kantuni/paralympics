#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<long long> b(a);
  long long ans = 0;
  for (int i = b.size() - 2; i > -1; i--) {
    long long diff = b[i + 1] - b[i];
    if (diff >= 0) {
      b[i] += diff + 1;
      ans += diff + 1;
    }
  }
  long long c = ans, diff = 0;
  for (int i = 1; i < b.size(); i++) {
    long long bpp = i > 1 ? b[i - 2] : -1;
    diff = max(bpp + 1, a[i - 1]) - b[i - 1];
    b[i - 1] += diff;
    c += diff;
    long long bn = i + 1 < b.size() ? b[i + 1] : 0;
    diff = max({b[i - 1] + 1, a[i], bn + 1}) - b[i];
    b[i] += diff;
    c += diff;
    ans = min(ans, c);
  }
  cout << ans << endl;
  return 0;

