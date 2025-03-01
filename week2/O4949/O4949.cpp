#include<bits/stdc++.h>
using namespace std;
vector<string> result;

bool check(string str){
    stack<char> stk;
    for(char ch : str){
        if(ch == '(' || ch == '[') stk.push(ch);
        else if(ch == ')' || ch == ']'){
            if(stk.size()){
                if(ch - stk.top() == 1 || ch - stk.top() == 2) stk.pop();
                else return false;
            }
            else return false;
        }
    }
    return stk.empty();
}

int main(){
    while(true){
        string input;
        getline(cin, input, '.');
        cin.ignore();
        if(input.empty()) break;
        if(check(input)) result.push_back("yes\n");
        else result.push_back("no\n");
    }
    for(string str : result) cout << str;
    return 0;
}