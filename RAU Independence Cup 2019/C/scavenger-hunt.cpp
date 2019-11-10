#include <bits/stdc++.h>
#define LIMIT (int) 1e9
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  long long pos = 0;
  long long h = 2;
  while (n > 0) {
    if (pos + h > LIMIT) {
      h = LIMIT - pos;
    } else if (pos + h < -LIMIT) {
      h = -1 * (pos + LIMIT);
    }
    pos += h;
    cout << h << endl;
    string s;
    long long x;
    cin >> s >> x;
    if (s == "Yes") {
      pos = x;
      h = 2;
      n--;
    } else {
      h *= -2;
    }
  }
  return 0;
}
