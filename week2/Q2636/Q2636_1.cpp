#include <bits/stdc++.h>
using namespace std;

int ny, nx, N, M, flag, cnt1, cnt2, Map[104][104], visited[104][104];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

bool IsHole(int y, int x){
    visited[y][x] = 1;
    if(flag == 1) return false;
    for(int i = 0; i < 4; i++){
        ny = y + dy[i];
        nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
        if(visited[ny][nx] || Map[ny][nx] != 0) continue;
        if(ny == 0 || nx == 0 || ny == N -1 || nx == M -1) flag = 1;
        return IsHole(ny,nx);
    }
    return true;
}
void Melt(int y, int x){
    for(int i = 0; i < 4; i++){
        ny = y + dy[i];
        nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
        if(Map[ny][nx] == 0) Map[y][x] = -1;
    }
}
bool check_last(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(Map[i][j] == 1) return false;
        }
    }
    return true;
}
void DFS(int y, int x){
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++){
        ny = y + dy[i];
        nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
        if(visited[ny][nx] || Map[ny][nx] != -1) continue;
        DFS(ny, nx);
    }
    return;
}

int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j ++){
            cin >> Map[i][j];
        }
    }
    while(!check_last()){
        cnt1++;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(Map[i][j] == 0){
                    flag = 0;
                    fill(&visited[0][0], &visited[0][0] + 104 * 104, 0);
                    if(IsHole(i,j)) Map[i][j] = 2;
                }
            }
        }
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(Map[i][j] == 1){
                    Melt(i, j);
                }
            }
        }
        if(check_last()){
            fill(&visited[0][0], &visited[0][0] + 104 * 104, 0);
            for(int i = 0; i < N; i++){
                for(int j = 0; j < M; j++){
                    if(Map[i][j] == -1 && !visited[i][j]){
                        cnt2++;
                        DFS(i,j);
                    }
                }
            }
            break;
        }
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(Map[i][j] == -1 || Map[i][j] == 2){
                    Map[i][j] = 0;
                }
            }
        }    
    }
    cout << cnt1 << "\n" << cnt2 << "\n";

    return 0;
}