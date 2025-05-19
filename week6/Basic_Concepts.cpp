#include <iostream>
#include <vector>

int BinarySearch(const std::vector<int> &arr, int target) {
  int left = 0;
  int right = arr.size() - 1;

  while (left <= right) {
    int mid = left + (right - left) / 2; // 그냥 (left + right) / 2 해버리면 overflow 가 나올 수도 있음
    if (arr[mid] == target) {
      return mid;
    } else if (arr[mid] < target) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  return -1; // target 값을 못 찾았을 때
}


int main() {
  std::vector<int> arr = {1, 3, 6, 9, 10, 21, 22, 30};
  int target = 6;
  int result = BinarySearch(arr, target);

  if (result != -1) {
    std::cout << "Target found at index : " << result << '\n';
  }
  else {
    std::cout << "Target not found in the array\n";
  }
  
  return 0;
}