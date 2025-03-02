// 치즈 속에 구멍이 있다는걸 이해하지 못한채로 코드를 짜서 다시 풀어야함..
#include<bits/stdc++.h>
using namespace std;

int N, M, cnt_time, cnt, Map[101][101], visited[101][101];
int ny, nx;
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
bool check0(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(Map[i][j] != 0) return false;
        }
    }
    return true;
}
bool check(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(Map[i][j] == 1) return true; // true 면 아직 녹일 치즈 남은 것.
        }
    }
    return false;
}

bool DFS_zero(int y, int x){
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++){
        ny = y + dy[i];
        nx = x + dx[i];
        if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
        if(Map[ny][nx] != 0 || visited[ny][nx])  continue;
        if(ny == 0 || nx == 0 || ny == N || nx == M) return false;
    }
    return true;
}
bool AirInCheese(int y, int x){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(Map[i][j] == 0){
                DFS_zero().....                             // Toooooooo Long code. Try again.
            }
        }
    }

}
void Hole(int y, int x){
    for(int i = 0; i < 4; i++){
        ny = y + dy[i];
        nx = x + dx[i];
        if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
        if(Map[ny][nx] == 0 && !AirInCheese(ny,nx)){
            Map[y][x] = 2;
            return;
        }
    }
    return;
}
void Melt(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(Map[i][j] == 2) Map[i][j] = 0;
        }
    }
    return;
}

void DFS(int y, int x){
    Map[y][x] = 0;
    for(int i = 0; i < 4; i++){
        ny = y + dy[i];
        nx = x + dx[i];
        if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
        if(Map[ny][nx] == 2) DFS(ny,nx); 
    }
    return;
}

int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> Map[i][j];
        }
    }
    if(check0()) {
        cout << "0\n0\n";
        return 0;
    }
    while(true){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(Map[i][j] == 1) Hole(i,j);
            }
        }
        cnt_time++;
        if(check() == false) break;
        else Melt();
    } 
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(Map[i][j] == 2){
                cnt++;
                DFS(i, j);
            } 
        }
    }
    cout << cnt_time << "\n" << cnt << "\n";
    return 0;
}