#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

std::vector<int> get_primes(int n) {
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
    if (is_prime[i]) {
      primes.push_back(i);
    }
  }

  return primes;
}

int main() {
  int n;
  std::cin >> n;

  std::vector<int> prime_numbers = get_primes(n);

  std::sort(prime_numbers.begin(), prime_numbers.end(), std::greater<int>());
  int size = prime_numbers.size();

  int result = 0;
  int sum = 0;
  std::priority_queue<int> pq;

  for (int i = 0; i < size; ++i) {
    int here = prime_numbers[i];
    sum += here;
    pq.push(here);

    if (sum == n) {
      ++result;
      sum -= pq.top();
      pq.pop();
    }
    else if (sum > n) {
      sum -= pq.top();
      pq.pop();
    }
  }

  std::cout << result << '\n';

  return 0;

}