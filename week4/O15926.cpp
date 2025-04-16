#include <iostream>
#include <string>
#include <stack>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    std::stack<int> stk = {};
    int result = 0;
    int invalid = -1;
    for (int i = 0; i < n; ++i) {
        char input = s[i];
        if (input == '(') {
            stk.push(i);
        }
        else {
            if (stk.empty()) {
                invalid = i;
            }
            else {
                stk.pop();
                if (stk.empty()) {
                    result = std::max(result, i - invalid);
                }
                else {
                    result = std::max(result, i - stk.top());
                }
            }
        }
    }

    std::cout << result << '\n';
    return 0;
}