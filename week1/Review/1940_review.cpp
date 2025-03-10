#include<bits/stdc++.h>
using namespace std;

int N, M, cnt, input[15004];


int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> input[i];
    }
    for(int i = 0; i < N; i++){
        for(int j = i + 1; j < N; j++){
            if(input[i] + input[j] == M) cnt++;
        }
    }
    cout << cnt << '\n';
    return 0;
}