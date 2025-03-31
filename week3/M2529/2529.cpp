#include<bits/stdc++.h>
using namespace std;

int k;
string ret, ret_max = "", ret_min = "";
char ineq[9];
bool visited[10];

void cmp(){
    if(ret_max.empty() || ret > ret_max) ret_max = ret;
    if(ret_min.empty() || ret < ret_min) ret_min = ret;
}

void go(){
    int cnt = ret.size();
    if(cnt == k + 1){
        cmp();
        return;
    }

    char prev = ret.back();
    char from = '0', to = '9';

    if(ineq[cnt - 1] == '<'){
        from = prev + 1;
    } else {
        to = prev - 1;
    }

    for(char i = from; i <= to; i++){
        int digit = i - '0';
        if(visited[digit]) continue;

        visited[digit] = true;
        ret.push_back(i);
        go();
        ret.pop_back();
        visited[digit] = false;
    }
}

int main(){
    cin >> k;
    for(int i = 0; i < k; i++){
        cin >> ineq[i];
    }

    for(char i = '0'; i <= '9'; i++){
        int digit = i - '0';
        visited[digit] = true;
        ret.push_back(i);
        go();
        ret.pop_back();
        visited[digit] = false;
    }
    
    cout << ret_max << '\n' << ret_min << '\n';
    return 0;
}