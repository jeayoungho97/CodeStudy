#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> ans;

int main() {
  int t;
  std::cin >> t;
  while(t--) {
    int h, w, n;
    std::cin >> h >> w >> n;

    int fr = (n - 1) % h + 1;
    int ed = (n - 1) / h + 1;

    std::string ret = std::to_string(fr);
    if (ed < 10) ret += '0' + std::to_string(ed);
    else ret += std::to_string(ed);

    ans.push_back(ret);
  }

  for (std::string s : ans) std::cout << s << '\n';
  return 0;
}