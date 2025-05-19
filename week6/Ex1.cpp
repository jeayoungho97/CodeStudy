#include <iostream>
#include <vector>
#include <algorithm>

int BS(const std::vector<int> &arr, int target) {
  int left = 0, right = arr.size() - 1;

  while(left <= right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] == target) {
      return mid;
    }
    else if (arr[mid] < target) {
      left = mid + 1;
    }
    else {
      right = mid - 1;
    }
  }

  return -1;
}

int main() {
  int t;
  std::cin >> t;

  while (t--) {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
      std::cin >> arr[i];
    }
    std::sort(arr.begin(), arr.end());

    int m;
    std::cin >> m;
    for (int i = 0; i < m; ++i) {
      int temp;
      std::cin >> temp;
      if (BS(arr, temp) != -1) {
        std::cout << "I remember\n";
      }
      else {
        std::cout << "I don't remember\n";
      }
    }
  }

  return 0;
}