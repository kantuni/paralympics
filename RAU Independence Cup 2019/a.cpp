#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  if (a.size() == 1) {
    cout << 0 << endl;
    return 0;
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
  long long diff = b[1] - b[0];
  if (diff >= 0) {
    b[0] += diff + 1;
    ans += diff + 1;
  }
  long long c = ans, cd = 0;
  for (int i = 1; i < b.size(); i++) {
    long long bpp = i > 1 ? b[i - 2] : -1;
    cd = max(bpp + 1, a[i - 1]) - b[i - 1];
    b[i - 1] += cd;
    c += cd;
    long long bn = i + 1 < b.size() ? b[i + 1] : 0;
    long long newb = max({b[i - 1] + 1, a[i], bn + 1});
    cd = newb - b[i];
    b[i] += cd;
    c += cd;
    ans = min(ans, c);
  }
  cout << ans << endl;
  return 0;
}
