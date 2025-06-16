#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct person {
  int age;
  std::string name;
  int order;
};

bool cmp(const person& a, const person& b) {
  if (a.age == b.age) {
    return a.order < b.order;
  }
  return a.age < b.age;
}

int main() {
  int n; 
  std::cin >> n;

  std::vector<person> people;
  for (int i = 0; i < n; ++i) {
    person temp;
    std::cin >> temp.age >> temp.name;
    temp.order = i;
    people.push_back(temp);
  }

  std::sort(people.begin(), people.end(), cmp);

  for (auto i : people) {
    std::cout << i.age << ' ' << i.name << '\n';
  }

  return 0;
}