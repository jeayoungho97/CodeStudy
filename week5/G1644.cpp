#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

int main() {
  int n;
  std::cin >> n;

  if (n == 1) {
    std::cout << 0 << '\n';
    return 0;
  }

  std::vector<int> prime_numbers = {2};
  for (int i = 3; i <= n; ++i) {
    bool is_prime = true;
    for (int a : prime_numbers) {
      if (i % a == 0) {
        is_prime = false;
      }
    }
    if(is_prime) prime_numbers.push_back(i);
  }

  std::sort(prime_numbers.begin(), prime_numbers.end(), std::greater<int>());
  int size = prime_numbers.size();

  int result = 0;
  int sum = 0;
  std::priority_queue<int> pq;

  for(int i = 0; i < size; ++i) {
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