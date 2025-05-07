#include <iostream>
#include <vector>
#include <unordered_map>

std::unordered_map<int, int> get_sub_sum_counts(const std::vector<int>& pizza) {
  std::unordered_map<int, int> count_map;
  int len = pizza.size();
  std::vector<int> extended(pizza.begin(), pizza.end());
  extended.insert(extended.end(), pizza.begin(), pizza.end());
  
  for (int size = 1; size < len; ++size) {
    int sum = 0;
    for (int i = 0; i < size; ++i) sum += extended[i];
    ++count_map[sum];

    for (int i = 1; i < len; ++i) {
      sum = sum - extended[i - 1] + extended[i + size - 1];
      ++count_map[sum];
    }
  }

  int total = 0;
  for (int v : pizza) total += v;
  ++count_map[total];

  return count_map;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int needs, N, M;
  std::cin >> needs >> N >> M;

  std::vector<int> A(N), B(M);
  for (int i = 0; i < N; ++i) std::cin >> A[i];
  for (int i = 0; i < M; ++i) std::cin >> B[i];

  auto a_count = get_sub_sum_counts(A);
  auto b_count = get_sub_sum_counts(B);

  int result = 0;

  if (a_count.count(needs)) result += a_count[needs];
  if (b_count.count(needs)) result += b_count[needs];

  for (const auto& [a_sum, a_freq] : a_count) {
    int rest = needs - a_sum;
    if (b_count.count(rest)) {
      result += a_freq * b_count[rest];
    }
  }

  std::cout << result << '\n';
  return 0;
}