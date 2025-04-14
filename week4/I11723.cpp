#include <iostream>
#include <string>
#include <vector>

bool S[21];

int operate (std::string op, int a) {
  if (op == "add" && S[a] == false) {
    S[a] = true;
  }
  if (op == "remove" && S[a] == true) {
    S[a] = false;
  }
  if (op == "check") {
    return S[a];
  }
  if (op == "toggle") {
    if(S[a]) S[a] = false;
    else S[a] = true;
  }
  if (op == "all") {
    for (bool& a : S) a = true;
  }
  if (op == "empty") {
    for (bool& a : S) a = false;
  }
  return 0;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int m;
  std::cin >> m;
  while (m--) {
    std::string op;
    std::cin >> op;
    if (op == "all" || op == "empty") operate(op, 0);
    else {
      int a;
      std::cin >> a;
      if(op == "check") std::cout << operate(op, a) << '\n';
      else operate(op, a);
    }
  }
  return 0;
}