#include<bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int N, min_T = INF;
char Coins[21][21];

void flip(int row){
    for(int i = 0; i < N; i++){
        if(Coins[row][i] == 'H') Coins[row][i] = 'T';
        if(Coins[row][i] == 'T') Coins[row][i] = 'H';
    }
}

void go(int row){
    if(row == N){
        int ret;
        for(int j = 0; j < N; j++){
            int cnt = 0;
            for(int i = 0; i < N; i++){
                if(Coins[i][j] == 'T') cnt++;
                cnt = min(cnt, N - cnt);
                ret += cnt;
            }
        }
        min_T = min(min_T, ret);
    }
    for(int i = row; i < N; i++){
        flip(i);
        go(i + 1);
        flip(i);
        go(i + 1);
    }
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> Coins[i][j];
        }
    }
    // 강의보고 힌트를 얻음 -> 가로 세로 모두 뒤집어서 2^40 경우의 수를 만들 필요 없음!
    go(0);
    cout << min_T << '\n';
    return 0;
}