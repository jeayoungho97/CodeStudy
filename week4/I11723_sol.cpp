#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int m, n = 0;
    std::cin >> m;

    const int FULL_MASK = (1 << 21) - 1;  // 모든 원소가 포함된 집합 (0~20)

    while (m--) {
        std::string command;
        int x;

        std::cin >> command;

        if (command == "add") {
            std::cin >> x;
            n |= (1 << x);
        } else if (command == "remove") {
            std::cin >> x;
            n &= ~(1 << x);
        } else if (command == "check") {
            std::cin >> x;
            std::cout << ((n & (1 << x)) ? 1 : 0) << '\n';
        } else if (command == "toggle") {
            std::cin >> x;
            n ^= (1 << x);
        } else if (command == "all") {
            n = FULL_MASK;
        } else if (command == "empty") {
            n = 0;
        }
    }

    return 0;
}
