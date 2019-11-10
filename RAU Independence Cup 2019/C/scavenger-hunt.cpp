#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  int h = pow(-1, rand() % 2);
  while (n > 0) {
    cout << h << endl;
    string s;
    int x;
    cin >> s >> x;
    if (s == "Yes") {
      h = pow(-1, rand() % 2);
      n--;
    } else {
      h *= -2;
    }
  }
  return 0;
}
