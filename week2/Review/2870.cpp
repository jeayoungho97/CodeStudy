#include<bits/stdc++.h>
using namespace std;

int N;
string temp;
vector<string> result;

bool compare(string str1, string str2){
    if(str1.size() == str2.size()) return str1 < str2;
    return str1.size() < str2.size();
}

void solve(string str){
    string ret = "";
    for(char ch : str){
        if(ch >= '0' && ch <= '9'){
            if(ret == "" || ret == "0") ret = ch;
            else ret += ch;
        }
        else if(ret != ""){
            result.push_back(ret);
            ret = "";
        }
    }
    if(ret != ""){
        result.push_back(ret);
    }
    return;
}

int main(){
    cin >> N;
    while(N--){
        cin.ignore();
        cin >> temp;
        solve(temp);
    }
    sort(result.begin(), result.end(), compare);
    for(string str : result) cout << str << '\n';
    return 0;
}

// 실수들
// string 은 '' 가 안됨.
// if, else 문으로 나눌 때 엄청 틀림.
// 결과 string 을 int 로 바꾸면 앞의 0이 자동적을 사라지나, 100자리까지는 int 로 저장 불가.