#include<iostream>
#include <set>
#include <algorithm>

bool isIn(std::set<int> &a, std::set<int> &b) {
  return std::includes(b.begin(), b.end(), a.begin(), a.end());
}

char check(std::set<int> &a, std::set<int> &b) {
  if (isIn(a, b) && isIn(b, a)) return '=';
  if (isIn(a, b) && !isIn(b, a)) return '<';
  if (!isIn(a, b) && isIn(b, a)) return '>';
  return '?';
}

int main(int argc, char** argv) {
	int test_case;
	int T;

	std::cin>>T;

	for(test_case = 1; test_case <= T; ++test_case) {
		int size_a, size_b;
    std::cin >> size_a >> size_b;

    std::set<int> a, b;

    for (int i = 0; i < size_a; ++i) {
      int temp;
      std::cin >> temp;
      a.insert(temp);
    }
    
    for (int i = 0; i < size_b; ++i) {
      int temp;
      std::cin >> temp;
      b.insert(temp);
    }

    std::cout << check(a, b) << '\n';
	}
  return 0;
}