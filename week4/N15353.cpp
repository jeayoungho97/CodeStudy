#include <iostream>
#include <string>

int arr[10001];

int main() {
  std::string a, b;
  std::cin >> a >> b;
  size_t a_size = a.length();
  size_t b_size = b.length();

  bool a_is_bigger = (a_size >= b_size) ? true : false;
  size_t size_max = (a_size >= b_size) ? a_size : b_size;
  size_t size_min = (a_size >= b_size) ? b_size : a_size;


  for (int i = 0; i < size_min; ++i) {
    arr[i] += a[a_size - i - 1] - '0';
    arr[i] += b[b_size - i - 1] - '0';
    if (arr[i] > 9) {
      arr[i] -= 10;
      ++arr[i + 1]; 
    }
  }

  for (int i = size_min; i < size_max; ++i) {
    arr[i] += a_is_bigger ? a[a_size - i - 1] - '0' : b[b_size - i - 1] - '0';
    if (arr[i] > 9) {
      arr[i] -= 10;
      ++arr[i + 1]; 
    }
  }

  std::string result = "";
  for (int i = (arr[size_max]) ? size_max : size_max - 1; i >= 0; --i) {
    result += std::to_string(arr[i]);
  }

  std::cout << result << '\n';
  return 0;
}