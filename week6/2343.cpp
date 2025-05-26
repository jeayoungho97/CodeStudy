#include <iostream>
#include <vector>
int n, m;

bool check(const std::vector<int> &arr, int val) {
  int sum = 0, cnt = 0;
  for (int i = 0; i < arr.size(); ++i) {
    if (arr[i] > val) return false;

    if (sum + arr[i] > val) {
      sum = arr[i];
      ++cnt;
    }
    else {
      sum += arr[i];
    }
  }
  if (sum > 0) ++cnt;
  return cnt <= m;
}

int main() {
  std::cin >> n >> m;

  std::vector<int> arr(n);
  int tot_sum = 0;
  for (int i = 0; i < n; ++i) {
    std::cin >> arr[i];
    tot_sum += arr[i];
  }

  int result = 987654321;
  int left = 1, right = tot_sum;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (!check(arr, mid)) {
      left = mid + 1;
    }
    else {
      result = std::min(result, mid);
      right = mid - 1;
    }
  }

  std::cout << result << '\n';
  return 0;
}