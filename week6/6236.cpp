#include <iostream>
#include <vector>
#include <algorithm>

int N, M, max = 0;
std::vector<int> arr;

bool check(int K) {
  int money = K, cnt = 1;
  for (int i = 0; i < arr.size(); ++i) {
    if (arr[i] > money) {
      ++cnt;
      money = K - arr[i];
    }
    else {
      money -= arr[i];
    }
  }

  return cnt <= M;
}

int solve(int sum) {
  int left = max, right = sum;
  while (left < right) {
    int mid = left + (right - left) / 2;
    if (check(mid)) {
      right = mid;
    }
    else {
      left = mid + 1;
    }
  }
  return left;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> N >> M;
  int sum = 0;
  for (int i = 0; i < N; ++i) {
    int temp;
    std::cin >> temp;
    arr.push_back(temp);
    sum += temp;
    max = std::max(temp, max);
  }

  int result = solve(sum);

  std::cout << result << '\n';
  return 0;
}