#include<bits/stdc++.h>
using namespace std;
int N;
string code, front, back;
vector<string> result;
int main(){
    cin >> N;
    cin >> code;
    int ast = code.find("*");
    front = code.substr(0, ast);
    back = code.substr(ast + 1);
    while(N--){
        string temp;
        cin >> temp;
        if(temp.size() < front.size() + back.size()){
            result.push_back("NE");
            continue;
        }
        string temp_front = temp.substr(0, front.size());
        string temp_back = temp.substr(temp.size() - back.size());
        if(temp_front == front && temp_back == back) result.push_back("DA");
        else result.push_back("NE");
    }
    for(string str : result) cout << str << '\n';
    return 0;
}