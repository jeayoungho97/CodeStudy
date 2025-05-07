#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
  int needs, N, M;
  std::cin >> N >> M;

  std::vector<int> A(N), B(N);
  for (int i = 0; i < N; ++i) std::cin >> A[i];
  for (int i = 0; i < M; ++i) std::cin >> B[i];

  auto get_sub_sums = [](const std::vector<int>& pizza) {
    std::vector<int> sums;
    int len = pizza.size();
    std::vector<int> extended(pizza.begin(), pizza.end());
    extended.insert(extended.end(), pizza.begin(), pizza.end());

    for (int size = 1; size < len; ++size) {
      int sum = 0;
      for (int i = 0; i < size; ++i) sum += extended[i];
      sums.push_back(sum);

      for (int i = 1; i < len; ++i) {
        sum = sum - extended[i - 1] + extended[i + size - 1];
        sums.push_back(sum);
      }
    }

    int total = 0;
    for (int v : pizza) total += v;
    sums.push_back(total);

    return sums;
  };

  auto a_sums = get_sub_sums(A);
  auto b_sums = get_sub_sums(B);

  std::unordered_map<int, int> a_count, b_count;
  for (int s : a_sums) ++a_count[s];
  for (int s : b_sums) ++b_count[s];

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