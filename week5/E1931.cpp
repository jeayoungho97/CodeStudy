#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int n;
  std::cin >> n;

  std::vector<std::pair<int, int>> meetings;

  for (int i = 0; i < n; ++i) {
    int start_time, end_time;
    std::cin >> start_time >> end_time;
    meetings.push_back({end_time, start_time});
  }

  std::sort(meetings.begin(), meetings.end());

  int ending = 0;
  int result = 0;
  for (auto meeting : meetings) {
    int start_time = meeting.second;
    int end_time = meeting.first;

    if (start_time >= ending) {
      ++result;
      ending = end_time;
    }
  }

  std::cout << result << '\n';
  return 0;
}