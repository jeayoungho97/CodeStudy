#include <iostream>
#include <string>
#include <vector>

int main(){
  int a, b, c;
  std::cin >> a >> b >> c;

  int product = a * b * c;
  std::string productStr = std::to_string(product);

  std::vector<int> digitCount(10, 0);

  for (char digit : productStr) {
      ++digitCount[digit - '0']; // 전위증가가 후위증가보다 더욱 명확한 의미를 가짐 
}                                // 후위증가는 클래스, 반복자, 스마트 포인터 같은 객체에서는 성능 차이가 남.

  for (int i = 0; i < 10; i++) {
    std::cout << digitCount[i] << '\n';
  }

  return 0;
}