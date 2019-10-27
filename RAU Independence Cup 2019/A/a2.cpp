#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  if (n == 1) {
    cout << 0 << endl;
    return 0;
  }
  if (n == 2) {
    cout << (a[0] == a[1]) << endl;
    return 0;
  }
  vector<long long> b(a);
  for (int i = 1; i < n; i++) {
    long long diff = b[i - 1] - b[i];
    if (diff >= 0) {
      b[i] += diff + 1;
    }
  }
  vector<long long> sb(n);
  for (int i = 1; i < n; i++) {
    sb[i] = sb[i - 1] + b[i] - a[i];
  }
  vector<long long> c(a);
  for (int i = n - 2; i > -1; i--) {
    long long diff = c[i + 1] - c[i];
    if (diff >= 0) {
      c[i] += diff + 1;
    }
  }
  vector<long long> sc(n);
  for (int i = n - 2; i > -1; i--) {
    sc[i] = sc[i + 1] + c[i] - a[i];
  }
  long long ans = min(sb[n - 1], sc[0]);
  for (int i = 1; i < n - 1; i++) {
    long long cost;
    if (b[i] > c[i + 1]) {
      cost = sb[i] + sc[i + 1];
    } else {
      cost = sb[i - 1] + sc[i];
    }
    ans = min(ans, cost);
  }
  cout << ans << endl;
  return 0;
}
