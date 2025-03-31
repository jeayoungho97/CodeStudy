#include<bits/stdc++.h>
using namespace std;

const int max_N = 21;
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};
int R, C, ret;
string s;
char a[max_N][max_N];
bool visited[30];

void DFS(int y, int x, int cnt){
    ret = max(ret, cnt);
    for(int i = 0; i < 4; i++){
        auto ny = y + dy[i];
        auto nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= R || nx >= C) continue;
        if(visited[a[ny][nx] - 'A']) continue;
        visited[a[ny][nx] - 'A'] = true;
        DFS(ny, nx, cnt + 1);
        visited[a[ny][nx] - 'A'] = false;
    }
    return;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> R >> C;
    for(int i = 0; i < R; i++){
        cin >> s;
        for(int j = 0; j < C; j++){
            a[i][j] = s[j];
        }
    }

    visited[a[0][0] - 'A'] = true;
    DFS(0, 0, 1);
    cout << ret << '\n';

    return 0;
}