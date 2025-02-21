#include<bits/stdc++.h>
using namespace std;

int N, M, cnt;
vector<int> front_half, back_half;
float mid;

int main(){
    cin >> N >> M;
    mid = M/2.0;
    for(int i = 0; i < N; i++){
        int temp;cin >> temp;
        if(temp < mid)front_half.push_back(temp);
        else back_half.push_back(temp);
    }
    if(M >= 200000){
        cout << 0 << "\n";
    } 
    else{
        for(int i = 0; i < front_half.size(); i++){
            if(find(back_half.begin(), back_half.end(), M - front_half[i]) != back_half.end())cnt++;
        }
        cout << cnt << "\n";
    }
    
    return 0;
}

// 왜 틀렸을까?