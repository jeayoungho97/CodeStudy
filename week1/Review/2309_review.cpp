#include<bits/stdc++.h>
using namespace std;
int sum, input[9], fakes[2];
vector<int> result;

void solve(){
    for(int i = 0; i < 9; i++){
        for(int j = i + 1; j < 9; j++){
            if(input[i] + input[j] == sum - 100){
                fakes[0] = i;
                fakes[1] = j;
                return;
            }
        }
    }
}
int main(){
    for(int i = 0; i < 9; i++){
        cin >> input[i];    
        sum += input[i];
    }
    solve();
    for(int i = 0; i < 9; i++){
        if(i == fakes[0] || i == fakes[1])continue;
        else result.push_back(input[i]);
    }
    sort(result.begin(), result.end());
    for(int i : result) cout << i << "\n";
    return 0;
}