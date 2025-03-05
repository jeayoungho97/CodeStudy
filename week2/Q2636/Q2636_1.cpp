#include <bits/stdc++.h>
using namespace std;
int ny, nx, N, M, cnt1, cnt2, Map[104][104], visited[104][104];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
bool IsHole(int y, int x){
    visited[y][x] = 1;
    if(y == 0 || x == 0 || y == N -1 || x == M - 1) return false;
    for(int i = 0; i < 4; i++){
        ny = y + dy[i];
        nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
        if(visited[ny][nx] || Map[ny][nx] != 0) continue;
        if(!IsHole(ny, nx)) return false;
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
int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j ++){
            cin >> Map[i][j];
        }
    }
    while(!check_last()){
        cnt1++;
        memset(visited, 0, sizeof(visited));
        for(int i = 1; i < N - 1; i++){
            for(int j = 1; j < M - 1; j++){
                if(!Map[i][j] && IsHole(i,j)){
                    Map[i][j] = 2;
                }
            }
        }
        for(int i = 1; i < N - 1; i++){
            for(int j = 1; j < M - 1; j++){
                if(Map[i][j] == 1){
                    Melt(i, j);
                }
            }
        }
        if(check_last()){
            for(int i = 1; i < N - 1; i++){
                for(int j = 1; j < M - 1; j++){
                    if(Map[i][j] == -1){
                        cnt2++;
                    }
                }
            }
            break;
        }
        for(int i = 1; i < N - 1; i++){
            for(int j = 1; j < M - 1; j++){
                if(Map[i][j] == -1 || Map[i][j] == 2){
                    Map[i][j] = 0;
                }
            }
        }    
    }
    cout << cnt1 << "\n" << cnt2 << "\n";
    return 0;
}
// 강사님의 답변을 받았으나 로직이 좀 답이 없다고 생각해서 일단 폐기