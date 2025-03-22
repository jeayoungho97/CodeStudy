#include<bits/stdc++.h>
using namespace std;
int N, HP[3];
array<int,3> atk = {9, 3, 1};
vector<array<int,3>> atks;
void func(){
    do{
        atks.push_back(atk);
    }while(prev_permutation(atk.begin(), atk.end()));
    for(auto i : atks){
        for(auto j : i){
            cout << j << " ";
        }
        cout << '\n';
    }
    return;
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++) cin >> HP[i];
    func();


    return 0;
}