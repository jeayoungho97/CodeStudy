#include<bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int N, min_T = INF;
char Coins[21][21];

void flip(int row){
    for(int i = 0; i < N; i++){
        if(Coins[row][i] == 'H') Coins[row][i] = 'T';
        else Coins[row][i] = 'H';
    }
}

void go(int row){
    if(row == N){
        int ret = 0;
        for(int j = 0; j < N; j++){
            int cnt = 0;
            for(int i = 0; i < N; i++){
                if(Coins[i][j] == 'T') cnt++;
            }
            ret += min(cnt, N - cnt);
        }
        min_T = min(min_T, ret);
        return;
    }
    go(row + 1);
    flip(row);
    go(row + 1);
    // flip(row);
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> Coins[i][j];
        }
    }
    go(0);
    cout << min_T << '\n';
    return 0;
}