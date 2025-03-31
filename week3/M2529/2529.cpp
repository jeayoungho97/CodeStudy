#include<bits/stdc++.h>
using namespace std;

int k;
string ret, ret_max = "000000000", ret_min = "999999999";
char ineq[10];
bool visited[10];

void cmp(){
    if(ret > ret_max) ret_max = ret;
    if(ret < ret_min) ret_min = ret;
}

void go(){
    char num = ret.back();
    int cnt = ret.size();
    if(cnt == k + 1){
        cmp();
        return;
    }
    if(ineq[cnt - 1] == '<'){
        for(char i = num + 1; i <= '9'; i++){
            if(visited[i - '0']) continue;
            ret.push_back(i);
            visited[i - '0'] = true;
            go();
            ret.pop_back();
            visited[i - '0'] = false;
        }
    }
    else{
        for(char i = '0'; i < num; i++){
            if(visited[i - '0']) continue;
            ret.push_back(i);
            visited[i - '0'] = true;
            go();
            ret.pop_back();
            visited[i - '0'] = false;
        }
    }
}

int main(){
    cin >> k;
    for(int i = 0; i < k; i++){
        cin >> ineq[i];
    }
    for(char i = '0'; i <= '9'; i++){
        ret.push_back(i);
        visited[i - '0'] = true;
        go();
        ret.pop_back();
        visited[i - '0'] = false;
    }
    cout << ret_max << '\n';
    cout << ret_min << '\n';
    return 0;
}