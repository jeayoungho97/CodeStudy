#include <iostream>
#include <vector>

int needs, N, M, result;
std::vector<int> pizza1, pizza2;
int psum1[1001], psum2[1001];

int main() {
  std::cin >> needs;
  std::cin >> N >> M;

  for (int i = 1; i <= N; ++i) {
    int temp;
    std::cin >> temp;
    psum1[i] = psum1[i - 1] + temp;
    pizza1.push_back(temp);
  }

  for (int i = 1; i <= M; ++i) {
    int temp;
    std::cin >> temp;
    psum2[i] = psum2[i - 1] + temp;
    pizza2.push_back(temp);
  }

  for (int i = 0; i < N; ++i) {
    for (int j = i + 1; j != i; ++j) {
      int sum;
      if (j >= N) j = 0;
      
      if (j < i) {
        sum = psum1[N] - psum1[i] + psum1[j];
      }
      else {
        sum = psum1[j] - psum1[i];
      }

      if (needs > psum2[M] + sum) continue;

      if (sum == needs) {
        ++result;
        break;
      }

      if (sum > needs) break;

      for (int k = 0; k < M; ++k) {
        for (int l = k + 1; l != k; ++l) {
          if (l >= M) l = 0;

          int sum2;
          if (l < k) {
            sum2 = psum2[M] - psum2[k] + psum2[l];
          }
          else {
            sum2 = psum2[l] - psum2[k];
          }

          int total = sum + sum2;

          if (total == needs) {
            ++result;
            break;
          }

          if (total > needs) break;
        }
      }
    }
  }

  for (int i = 0; i < M; ++i) {
    for (int j = i + 1; j != i; ++j) {
      int sum;
      if (j >= M) j = 0;
      
      if (j < i) {
        sum = psum2[N] - psum2[i] + psum2[j];
      }
      else {
        sum = psum2[j] - psum2[i];
      }

      if (sum == needs) {
        ++result;
        break;
      }

      if (sum > needs) break;
    }
  }

  std::cout << result << '\n';

  return 0;
}