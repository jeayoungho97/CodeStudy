#include <iostream>
#include <string>
#include <algorithm>

constexpr int kMaxWords = 51;
constexpr int kAlphabetCount = 26;

// 입력
int n, k;
int word_masks[kMaxWords];
std::string input;

// 필수 알파벳 (antic)
constexpr int kMandatoryMask =
    (1 << ('a' - 'a')) |
    (1 << ('n' - 'a')) |
    (1 << ('t' - 'a')) |
    (1 << ('i' - 'a')) |
    (1 << ('c' - 'a'));

// 읽을 수 있는 단어 수 계산
int CountReadableWords(int learned_mask) {
  int count = 0;
  for (int i = 0; i < n; ++i) {
    int word = word_masks[i];
    if (word && (word & learned_mask) == word) {
      ++count;
    }
  }
  return count;
}

// 알파벳 조합 탐색 (DFS)
int MaxReadable(int index, int remaining, int learned_mask) {
  if (remaining < 0) return 0;
  if (index == kAlphabetCount) return CountReadableWords(learned_mask);

  // 현재 알파벳을 배우는 경우
  int max_result = MaxReadable(index + 1, remaining - 1,
                               learned_mask | (1 << index));

  // 현재 알파벳이 필수 알파벳이 아닌 경우 → 배우지 않는 경우도 고려
  if ((kMandatoryMask & (1 << index)) == 0) {
    max_result = std::max(max_result,
                          MaxReadable(index + 1, remaining, learned_mask));
  }

  return max_result;
}

int main() {
  std::cin >> n >> k;

  if (k < 5) {
    std::cout << 0 << '\n';  // antic조차 못 배우는 경우
    return 0;
  }

  for (int i = 0; i < n; ++i) {
    std::cin >> input;
    for (char ch : input) {
      word_masks[i] |= (1 << (ch - 'a'));
    }
  }

  // 필수 알파벳 5개는 이미 배운 것으로 간주하고 시작
  int result = MaxReadable(0, k - 5, kMandatoryMask);
  std::cout << result << '\n';
  return 0;
}
