#include <bits/stdc++.h>
using namespace std;

const int max_n = 500000;
int visited[2][max_n + 1], a, b, turn = 1;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> a >> b;
    if (a == b) {
        cout << 0 << "\n";
        return 0;
    }

    queue<int> q;
    visited[0][a] = 1;
    q.push(a);

    while (!q.empty()) {
        b += turn;
        if (b > max_n) break;  

        if (visited[turn % 2][b]) {
            cout << turn << "\n";
            return 0;
        }

        int qSize = q.size();
        for (int i = 0; i < qSize; i++) {
            int x = q.front();
            q.pop();

            for (int nx : {x + 1, x - 1, x * 2}) {
                if (nx < 0 || nx > max_n || visited[turn % 2][nx]) continue;

                visited[turn % 2][nx] = 1;
                if (nx == b) {
                    cout << turn << "\n";
                    return 0;
                }
                q.push(nx);
            }
        }
        turn++;
    }

    cout << -1 << "\n";
    return 0;
}
