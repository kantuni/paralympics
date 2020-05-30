#include <bits/stdc++.h>
#define P 1000000007
using namespace std;

long long fpow(long long x, long long n) {
  long long ans = 1;
  while (n > 0) {
    if (n % 2 == 0) {
      x = (x * x) % P;
      n /= 2;
    } else {
      ans = (ans * x) % P;
      n--;
    }
  }
  return ans;
}

// TODO
// Find the number of strings of length n
// not containing pattern of length k (different letters)

long long f(long long n, long long k) {
  // Number of strings of length n 
  // containing pattern of length k (same letter) =
  // (n - k + 1) * 26 ^ (n - k) - (n - k) * 26 ^ (n - k - 1)
  if (k > n) {
    return fpow(26, n);
  }
  long long a = fpow(26, n - k) * (n - k + 1) % P;
  long long b = fpow(26, n - k - 1) * (n - k) % P;
  return fpow(26, n) - (a - b);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n;
  cin >> n;
  string xa, xb;
  int ka, kb;
  cin >> xa >> ka;
  cin >> xb >> kb;
  long long ans = 0;
  for (int i = 0; i <= n; i++) {
    ans += f(i, xa.size() + ka) * f(n - i, xb.size() + kb);
    ans %= P;
  }
  cout << ans << endl;
  return 0;
}
