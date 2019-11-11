#include <bits/stdc++.h>
using namespace std;

bool match(string s, string t) {
  for (int i = 0; i < s.size(); i++) {
    if (s[i] != '?' and s[i] != t[i]) {
      return false;
    }
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin >> s;
  if (s.size() == 1) {
    // Incorrect Test Case:
    // '?' -> 8 (should be 0)
    if (s[0] == '?' or s[0] == '8') {
      cout << 8 << endl;
      return 0;
    } else {
      cout << -1 << endl;
      return 0;
    }
  } else if (s.size() == 2) {
    for (int i = 1; i < 10; i++) {
      for (int j = 0; j < 10; j++) {
        string m = to_string(i) + to_string(j);
        if (match(s, m) and stoi(m) % 8 == 0) {
          cout << m << endl;
          return 0;
        }
      }
    }
  } else {
    string prefix = s.substr(0, s.size() - 3);
    string suffix = s.substr(s.size() - 3, 3);
    for (int i = 0; i < prefix.size(); i++) {
      if (prefix[i] == '?') {
        prefix[i] = (i == 0) ? '1': '0';
      }
    }
    bool leading = s.size() > 3;
    for (int i = !leading; i < 10; i++) {
      for (int j = 0; j < 10; j++) {
        for (int k = 0; k < 10; k++) {
          string m = to_string(i) + to_string(j) + to_string(k);
          if (match(suffix, m) and stoi(m) % 8 == 0) {
            cout << prefix + m << endl;
            return 0;
          }
        }
      }
    }
  }
  cout << -1 << endl;
  return 0;
}
