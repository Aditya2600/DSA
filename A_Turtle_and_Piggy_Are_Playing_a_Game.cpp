#include <iostream>
using namespace std;

int max_score(int l, int r) {
  // Find the minimum prime factor of the upper limit (r)
  int min_prime = r;
  for (int i = 2; i * i <= r; i++) {
    if (r % i == 0) {
      min_prime = min(min_prime, i);
      break;
    }
  }

  // Count the number of divisions needed to reach 1 from r using the minimum prime factor
  int count = 0;
  while (r > 1) {
    if (r % min_prime == 0) {
      r /= min_prime;
      count++;
    } else {
      // If r is not divisible by the minimum prime, no further prime factorization is possible
      break;
    }
  }

  return count;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int l, r;
    cin >> l >> r;
    cout << max_score(l, r) << endl;
  }
  return 0;
}
