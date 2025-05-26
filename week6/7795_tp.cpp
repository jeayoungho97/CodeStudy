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

    std::sort(arr1.begin(), arr1.end());
    std::sort(arr2.begin(), arr2.end());

    int result = 0;

    int j = 0;
    for (int i = 0; i < N; ++i) {
      while (j < M && arr2[j] < arr1[i]) ++j;
      result += j;
    }

    std::cout << result << '\n';
  }
  return 0;  
}