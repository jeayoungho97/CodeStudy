// Stack.........
// Stack 을 쓰는게 처음이라 생각도 못했다.
// 답지 보고 베낌..
#include<bits/stdc++.h>
using namespace std;
int N, cnt;
string input;

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> input;
        stack<char> stk;
        for(char a : input){
            if(stk.size() && stk.top() == a)stk.pop();
            else stk.push(a);
        }
        if(stk.size() == 0)cnt++;
    }
    cout << cnt << "\n";
    return 0;
}