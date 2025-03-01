#include<bits/stdc++.h>
using namespace std;
stack<char> stk;
string str;
vector<string> result;
int main(){
    int N;
    cin >> N;
    while(N--){
        cin >> str;
        for(char ch : str){
            if(stk.size() && stk.top() == '(' && ch == ')') stk.pop();
            else stk.push(ch);
        }
        if(stk.size() == 0) result.push_back("YES");
        else result.push_back("NO");
        // for(int i = 0; i < stk.size(); i++) stk.pop(); <- 이게 안되는걸 왜 지피티에 물어봐야만 알았을까?
        while(!stk.empty()) stk.pop();
    }
    for(string str : result)cout << str << "\n";
    return 0;
}