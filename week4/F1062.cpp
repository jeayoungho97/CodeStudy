#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

// 단어의 가르침 유무를 비트마스킹으로 처리
// 인풋의 단어들 또한 비트마스킹
// 두 단어를 & 연산한 결과가 인풋과 같다면 결과 + 1
// 결과의 최댓값을 구함

int n, k;
int antic;
int result = 0;
std::vector<int> words;

void num_antic(){
  int temp = 1;
  std::string antic_str = "antic";
  for (int i = 0; i < 26; ++i) {
    if(std::find(antic_str.begin(), antic_str.end(), i + 'a') != antic_str.end()) {
      antic += temp;
    }
    temp *= 2;
  }
}

void go(int number, int start) {
  int count = 0;
  for (int i = 0; i < 26; ++i) {
    if((number) & (1 << i)) ++count;
  }

  if (count == k) {
    int temp = 0;
    int size = words.size();
    for (int i = 0; i < size; ++i) {
      if ((words[i] & number) == words[i]) {
        ++temp;
      }
    }
    result = std::max(result, temp);
  }

  for (int i = start; i < 26; ++i) {
    if(number & (1 << start) == 0)
  }
}

int main() {
  std::cin >> n >> k;

  for (int i = 0; i < n; ++i) {
    std::string input;
    std::cin >> input;

    int num_bit = 0;
    int temp = 1;

    for (int j = 0; j < 26; ++j) {
      if(std::find(input.begin(), input.end(), j + 'a') != input.end()) {
        num_bit += temp;
      }
      temp *= 2;
    }
    words.push_back(num_bit);
  }

  // a n t i c 는 이미 포함한채로 k - 5 개의 새로운 문자를 가르침
  num_antic();
  go(antic, 0);

  std::cout << result << '\n';
  return 0;
}