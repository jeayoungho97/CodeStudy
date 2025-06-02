#include <iostream>

const int m = 1234567891;
long long thirty_one[54];

void calc() {
  long long a = 1;
  for (int i = 0; i < 50; ++i) {
    thirty_one[i] = a;
    a *= 31;
    a %= m;
  }
}

int main() {
  int n;
  std::cin >> n;
  calc();
  
  long long ret = 0;
  for (int i = 0; i < n; ++i) {
    char ch;
    std::cin >> ch;
    long long a = ch - 'a' + 1;
    a *= thirty_one[i];
    a %= m;

    ret += a;
    ret %= m;
  }

  std::cout << ret << '\n';
  return 0;
}