#include<bits/stdc++.h>
using namespace std;

int brk = 0, sum = 0;
vector<int> dwarfs, faker;
pair<int,int> ret;

void combi(int start, vector<int> &faker){
    if(faker.size() == 2){                                          // 9C7 -> 9C2 로 바꿨는데 메모리를 더 쓰고 코드도 더 길어짐.
        int two_sum = accumulate(faker.begin(), faker.end(), 0);  
        if(two_sum == sum - 100){
            brk = 1;                                            
            ret = {faker[0],faker[1]};
            sort(dwarfs.begin(),dwarfs.end());                  
            for(int i : dwarfs){
                if(ret.first == i || ret.second == i)continue;
                cout << i << "\n";
            }               
        }
        return;
    }
    for(int i = start; i < 9; i++){
        if(brk == 1)break;                                      
        faker.push_back(dwarfs[i]);
        combi(start + 1, faker);
        faker.pop_back();                                      
    }
}

int main(){
    for(int i = 0; i < 9; i++){
        int input;
        cin >> input;
        dwarfs.push_back(input);
        sum += input;
    }
    combi(0,faker);                                            
    return 0;
}