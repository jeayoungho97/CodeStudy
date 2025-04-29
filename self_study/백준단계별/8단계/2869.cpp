#include <iostream>

int main() {
  int A, B, V;
  std::cin >> A >> B >> V;
  int result = 1;
  result += (V - A) / (A - B);
  if ((V - A) % (A - B) != 0) {
    ++result;
  }
  std::cout << result << '\n';
  return 0;
}