#include<bits/stdc++.h>
using namespace std;

int Node[1024], visited[1024];
vector<int> level[11];

void go(int fr, int en, int lev){
    if(fr > en) return;
    if(fr == en) {
        level[lev].push_back(Node[fr]);
        return;
    }
    int mid = (fr + en) / 2;
    level[lev].push_back(Node[mid]);
    go(fr, mid - 1, lev + 1);
    go(mid + 1, en, lev + 1);
    return;
}

int main(){
    int K;
    cin >> K;
    int K2 = (int)pow(2, K) - 1;

    for(int i = 0; i < K2; i++){
        cin >> Node[i];
    }
    go(0, K2, 0);
    for(int i = 0; i < K; i++){
        for(int j : level[i]){
            cout << j << " ";
        }
        cout << '\n';
    }
    return 0;
}