#include <iostream>
#include <algorithm>

int main() {
  while(true) {
    int a, b, c;
    std::cin >> a >> b >> c;
    if (a == 0 && b == 0 && c == 0) break;

    int arr[3] = {a, b, c};
    std::sort(arr, arr + 3);

    if ((arr[2] * arr[2] - arr[1] * arr[1] - arr[0] * arr[0]) == 0) std::cout << "right\n";
    else std::cout << "wrong\n";
  }

  return 0;
}