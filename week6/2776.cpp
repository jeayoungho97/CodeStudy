#include <iostream>
#include <vector>
#include <algorithm>

void check(const std::vector<int> &arr1, const std::vector<int> &arr2) {

  for (int i : arr2) {
    int left = 0, right = arr1.size();
    bool flag = false;
    while (left <= right) {
      int mid = left + (right - left) / 2;

      if (i < arr1[mid]) {
        right = mid - 1;
      }
      else if (i > arr1[mid]) {
        left = mid + 1;
      }
      else {
        flag = true;
        break;
      }
    }

    if (flag) std::cout << 1 << '\n';
    else std::cout << 0 << '\n';
  }


}

int main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n, m;
    std::cin >> n;
    std::vector<int> arr1(n);

    for (int i = 0; i < n; ++i) {
      std::cin >> arr1[i];
    }
    std::sort(arr1.begin(), arr1.end());

    std::cin >> m;
    std::vector<int> arr2(m);

    for (int i = 0; i < m; ++i) {
      std::cin >> arr2[i];
    }

    check(arr1, arr2);
  }


  return 0;
}