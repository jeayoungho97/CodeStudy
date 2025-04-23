#include <iostream>
#include <vector>

std::vector<int> make_prime(int n) {
  std::vector<bool> is_prime(n + 1, true);
  is_prime[0] = is_prime[1] = false;

  for (int i = 2; i * i <= n; ++i) {
    if (is_prime[i]) {
      for (int j = i * i; j <= n; j += i) {
        is_prime[j] = false;
      }
    }
  }

  std::vector<int> primes;
  for (int i = 2; i <= n; ++i) {
    if(is_prime[i]) {
      primes.push_back(i);
    }
  }
  
  return primes;
}

int main() {
  int n;
  std::cin >> n;

  std::vector prime_numbers = make_prime(n);

  int result = 0, left = 0, right = 0, sum = 0;
  
  while (true) {
    if (sum >= n) sum -= prime_numbers[left++];
    else if (right == prime_numbers.size()) break;
    else sum += prime_numbers[right++];

    if (sum == n) ++result;
  }

  std::cout << result << '\n';
  return 0;
}