#include<bits/stdc++.h>
using namespace std;
#define y1 aaa

int N, M;
int x1, x2, y1, y2;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int visited[301][301];
char Map[301][301];
queue<pair<int,int>> q;

void four_search(int y, int x, int step){
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
        if(visited[ny][nx]) continue;

        visited[ny][nx] = step;

        if(Map[ny][nx] == '0'){
            four_search(ny, nx, step);
        } else {
            q.push({ny,nx});
        }
    }
}

int main(){
    cin >> N >> M;
    cin >> y1 >> x1 >> y2 >> x2;
    y1--;x1--;y2--;x2--;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> Map[i][j];
        }
    }

    q.push({y1, x1});
    visited[y1][x1] = 1;
    int step = 1;

    while(!q.empty()){
        int qSize = q.size();

        for(int i = 0; i < qSize; i++){
            auto [y, x] = q.front(); q.pop();
            four_search(y, x, step);
        }

        if(visited[y2][x2]) {
            cout << step << '\n';
            return 0;
        }

        step++;
    }

    cout << "-1\n";
    return 0;
}