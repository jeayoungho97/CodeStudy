//Code made by myself -> Using Combination => Better than Permutation?
//9C7 = 9C2 = 9P2 / 2
//9C2 의 Method 로 코드를 짜야함

#include<bits/stdc++.h>
using namespace std;

int brk = 0;
vector<int> dwarfs, result;

void combi(int start, vector<int> &result){
    if(result.size() == 7){

//MAIN LOGIC
        int sum = accumulate(result.begin(), result.end(), 0);  // accumulate 함수를 이용해 7 요소의 합 구함
        if(sum == 100){
            brk = 1;                                            // 합이 100이 되었으므로 이후의 모든 for문을 break
            sort(result.begin(),result.end());                  
            for(int j : result)cout << j << "\n";               // sort 하고 print
        }
//MAIN LOGIC

        return;
    }
    for(int i = start; i < 9; i++){
        if(brk == 1)break;                                      // breakpoint
        result.push_back(dwarfs[i]);
        combi(start + 1, result);
        result.pop_back();                                      // Combination 의 recursion 문법
    }
}

int main(){
// 9개의 난쟁이의 키를 cin 으로 받아 global vector인 dwarfs 에 저장
    for(int i = 0; i < 9; i++){
        int input;
        cin >> input;
        dwarfs.push_back(input);
    }
    combi(0,result);                                            // 0번째부터 시작
    return 0;
}