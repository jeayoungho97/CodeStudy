#include <iostream>
#include <string>

int main() {
  std::string str;
  std::string pyungjum; // 자괴감이 드는 변수명
  double hakjum, cur_pyungjum, total_hakjum = 0, total_pyungjum = 0;

  for (int i = 0; i < 20; ++i) {
    std::cin >> str >> hakjum >> pyungjum; 

    if (pyungjum == "P") continue;

    total_hakjum += hakjum;
    
    if (pyungjum == "F") continue;

    cur_pyungjum = 4 - (pyungjum[0] - 'A');
    if (pyungjum[1] == '+') cur_pyungjum += 0.5;

    total_pyungjum += (cur_pyungjum * hakjum);
  }

  std::cout << total_pyungjum / total_hakjum << '\n';
  return 0;
}