#include<bits/stdc++.h>
using namespace std;
int nx, H, W;
int visited[100][100];
void DFS(int y, int x){
    nx = x + 1;
    if(nx >= W || visited[y][nx] == 0) return;
    else{
        visited[y][nx] = visited[y][x] + 1;
        DFS(y,nx);
    }
    return;
}

int main(){
    fill(&visited[0][0], &visited[0][0] + 100 * 100, -1);
    cin >> H >> W;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            char ch;
            cin >> ch;
            if(ch == 'c')visited[i][j] = 0;
        }
    }
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(visited[i][j] == 0) DFS(i,j);
        }
    }

    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cout << visited[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}