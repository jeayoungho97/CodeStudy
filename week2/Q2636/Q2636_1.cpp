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
// 0 이 구멍인지 아닌지 확인하는 함수. 구멍이면 true, 구멍이 아니면 false 반환.


void Melt(int y, int x){
    for(int i = 0; i < 4; i++){
        ny = y + dy[i];
        nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
        if(Map[ny][nx] == 0) Map[y][x] = -1;
    }
}
// 외부공기에 닿은 치즈를 1 -> -1 로 바꿔줌

bool check_last(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(Map[i][j] == 1) return false;
        }
    }
    return true;
}
// Map 에 치즈(1) 가 남아있는지 아닌지 확인하는 함수

int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j ++){
            cin >> Map[i][j];
        }
    }
    while(!check_last()){                   // !check_last() 를 통해 0으로만 이루어진 인풋인 경우 0 0 출력
        cnt1++;                             // cnt1 -> 치즈가 녹는데 걸리는 시간
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(Map[i][j] == 0){
                    flag = 0;
                    fill(&visited[0][0], &visited[0][0] + 104 * 104, 0);
                    if(IsHole(i,j)) Map[i][j] = 2;
                }
            }
        }
        // 치즈 속의 공기라면 0 -> 2 로 바꿔줌

        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(Map[i][j] == 1){
                    Melt(i, j);
                }
            }
        }
        // 모든 치즈(1)에 대해 외부 공기와 닿는지 확인 후 닿으면 -1 로 변경

        if(check_last()){
            fill(&visited[0][0], &visited[0][0] + 104 * 104, 0);
            for(int i = 0; i < N; i++){
                for(int j = 0; j < M; j++){
                    if(Map[i][j] == -1){
                        cnt2++;
                    }
                }
            }
            break;
        }
        // 현 시점에서 모든 치즈가 -1 로 변해 1이 모두 없어졌다면, 그 수를 세서 cnt2 에 저장.

        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(Map[i][j] == -1 || Map[i][j] == 2){
                    Map[i][j] = 0;
                }
            }
        }    
        // 위의 check_last 가 false 라면 -1 로 바뀌었던 치즈와 2 로 바뀌었던 구멍이 공기(0) 으로 바뀜.
        // while 문으로 다시 반복.
    }
    cout << cnt1 << "\n" << cnt2 << "\n";

    return 0;
}