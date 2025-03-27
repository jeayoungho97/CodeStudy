#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 500000;
bool visited[2][MAX_N + 1];

int BFS(int start, int target){
    if(start == target) return 0;

    queue<int> q;
    q.push(start);
    visited[0][start] = true;

    int time = 0;
    while(!q.empty()){
        target += ++time;
        if(target > MAX_N) return -1;

        int size = q.size();
        for(int i = 0; i < size; i++){
            int curr = q.front();
            q.pop();
            for(int next : {curr - 1, curr + 1, curr * 2}){
                if(next < 0 || next > MAX_N) continue;
                if(visited[time % 2][next]) continue;
                visited[time % 2][next] = true;
                q.push(next);
            }
        }

        if(visited[time % 2][target]) return time;
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b;
    cin >> a >> b;
    cout << BFS(a, b) << '\n';

    return 0;
}