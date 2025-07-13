#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    std::string str1, str2;
    std::cin >> str1 >> str2;

    int n = str1.size();
    int m = str2.size();

    // dp[i][j]: str1[0..i-1], str2[0..j-1]의 LCS 길이
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));

    // DP 테이블 채우기
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (str1[i] == str2[j]) {
                dp[i + 1][j + 1] = dp[i][j] + 1;
            } else {
                dp[i + 1][j + 1] = std::max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
    }

    // LCS 복원
    std::string lcs;
    int i = n, j = m;
    while (i > 0 && j > 0) {
        if (str1[i - 1] == str2[j - 1]) {
            lcs += str1[i - 1];
            --i;
            --j;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            --i;
        } else {
            --j;
        }
    }

    std::reverse(lcs.begin(), lcs.end());
    std::cout << lcs << '\n';

    return 0;
}
