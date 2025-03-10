#include<bits/stdc++.h>
using namespace std;

int N, cnt;
string input;

int main(){
    cin >> N;
    while(N--){
        stack<char> stk;
        cin >> input;
        for(char ch : input){
            if(stk.size() && stk.top() == ch) stk.pop();
            else stk.push(ch);
        }
        if(!stk.size()) cnt++;
    }
    cout << cnt << '\n';
    return 0;
}