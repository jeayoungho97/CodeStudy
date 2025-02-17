//Code made by my own -> sloppy!

#include<bits/stdc++.h>
using namespace std;
int brk = 0;

void combi(int start,vector<int> &result, vector<int> &dwarfs){
    if(result.size() == 7){
        int sum = accumulate(result.begin(), result.end(), 0);
        if(sum == 100){
            brk = 1;
            sort(result.begin(),result.end());
            for(int j : result)cout << j << "\n";
        }
        return;
    }
    for(int i = start; i < 9; i++){
        if(brk == 1)break;
        result.push_back(dwarfs[i]);
        combi(start + 1, result, dwarfs);
        result.pop_back();
    }
}

int main(){
    vector<int> dwarfs, result;
    for(int i = 0; i < 9; i++){
        int input;
        cin >> input;
        dwarfs.push_back(input);
    }
    combi(0,result,dwarfs);
    return 0;
}