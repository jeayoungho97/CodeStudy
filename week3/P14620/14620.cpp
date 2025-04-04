#include<bits/stdc++.h>
using namespace std;

int N, ret = 3000, price[11][11]; 
bool visited[11][11];
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};


void go(int cnt){
    if(cnt == 3){
        int money = 0;
        for(int y = 0; y < N; y++){
            for(int x = 0; x < N; x++){
                if(visited[y][x]) money += price[y][x];
            }
        }
        ret = min(ret, money);
        return;
    }
    for(int y = 0; y < N; y++){
        for(int x = 0; x < N; x++){
            bool flag = true;
            if(visited[y][x]) flag = false;
            for(int i = 0; i < 4; i++){
                int ny = y + dy[i];
                int nx = x + dx[i];
                if(ny < 0 || nx < 0 || ny >= N || nx >= N || visited[ny][nx]) flag = false;
            }
            if(flag){
                visited[y][x] = true;
                for(int i = 0; i < 4; i++){
                    int ny = y + dy[i];
                    int nx = x + dx[i];
                    visited[ny][nx] = true;
                }
                go(cnt + 1);
                visited[y][x] = false;
                for(int i = 0; i < 4; i++){
                    int ny = y + dy[i];
                    int nx = x + dx[i];
                    visited[ny][nx] = false;
                }
            }
        }
    }
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> price[i][j];
        }
    }
    go(0);
    cout << ret << '\n';
    return 0;
}