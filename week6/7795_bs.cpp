#include <iostream>
#include <algorithm>
#include <vector>

int main() {
  int t;
  std::cin >> t;
  while(t--) {
    int N, M;
    std::cin >> N >> M;
    std::vector<int> arr1(N), arr2(M);

    for (int i = 0; i < N; ++i) {
      std::cin >> arr1[i];
    }
    for (int i = 0; i < M; ++i) {
      std::cin >> arr2[i];
    }

    std::sort(arr2.begin(), arr2.end());

    int result = 0;

    for (int i = 0; i < N; ++i) {
      int here = arr1[i];
      int left = 0, right = M;
      while (left < right) {
        int mid = left + (right - left) / 2;

        if (arr2[mid] >= here) {
          right = mid;
        }
        else {
          left = mid + 1;
        }
      }
      result += left;
    }

    std::cout << result << '\n';
  }


  return 0;  
}