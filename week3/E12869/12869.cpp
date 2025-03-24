#include<bits/stdc++.h>
using namespace std;

int x, y, z, nx, ny, nz, N, HP[3], visited[61][61][61];
array<int,3> atk = {9, 3, 1};
vector<array<int,3>> atks;


// 9 3 1 의 순열을 배열로 만들어 벡터에 저장하는 함수
void func(){
    do{
        atks.push_back(atk);
    }while(prev_permutation(atk.begin(), atk.end()));
    return;
}

int main(){
    // input 입력받고
    cin >> N;
    for(int i = 0; i < N; i++) cin >> HP[i];
    // 9,3,1 배열 만든 다음
    func();
    // BFS 수행
    queue<array<int,3>> q;
    q.push({HP[0],HP[1],HP[2]});
    visited[HP[0]][HP[1]][HP[2]] = 1;
    while(q.size()){
        x = q.front()[0];
        y = q.front()[1];
        z = q.front()[2];
        q.pop();
        if(visited[0][0][0]) break;
        for(int i = 0; i < 6; i++){
            nx = max(0, x - atks[i][0]);
            ny = max(0, y - atks[i][1]);
            nz = max(0, z - atks[i][2]);
            if(visited[nx][ny][nz]) continue;
            q.push({nx, ny, nz});
            visited[nx][ny][nz] = visited[x][y][z] + 1;
        }
    }
    cout << visited[0][0][0] - 1 << '\n';
    return 0;
}