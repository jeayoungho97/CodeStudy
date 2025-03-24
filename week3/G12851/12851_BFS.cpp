#include <bits/stdc++.h>
using namespace std;

int N, K;
int visited[100001];  // 0으로 초기화됨
int cnt;  // 최단 시간으로 도달하는 경우의 수

void bfs() {
    queue<pair<int, int>> q;
    q.push({N, 0});  // {현재 위치, 시간}
    visited[N] = 1;
    
    int minTime = -1;

    while (!q.empty()) {
        int cur = q.front().first;
        int time = q.front().second;
        q.pop();

        if (cur == K) {
            if (minTime == -1) {
                minTime = time;  // 최단 시간 저장
            }
            if (time == minTime) {
                cnt++;  // 최단 시간과 같은 경로 개수 증가
            }
        }

        for (int next : {cur - 1, cur + 1, cur * 2}) {
            if (next < 0 || next > 100000) continue;
            if (!visited[next] || visited[next] == time + 1) {  // 처음 방문하거나 같은 시간에 방문 가능
                q.push({next, time + 1});
                visited[next] = time + 1;
            }
        }
    }

    cout << minTime << '\n';
    cout << cnt << '\n';
}

int main() {
    cin >> N >> K;
    bfs();
    return 0;
}
