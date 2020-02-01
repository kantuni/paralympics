#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, a;
  cin >> n >> a;
  int start = a - (1 << (n - 1)) + 1;
  if (start <= 0) {
    cout << -1 << endl;
    return 0;
  }
  int i = 0;
  while (i < n) {
    for (int j = 0; j < n - 1 - i; j++) {
      cout << (1 << i) << " ";
    }
    cout << start << endl;
    start += (1 << i);
    i++;
  }
  return 0;
}
