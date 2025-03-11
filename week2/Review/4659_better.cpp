#include<bits/stdc++.h>
using namespace std;

string temp;
int vcnt, ccnt;
vector<string> result;
const string vowel = "aeiou";

bool is_vowel(char ch){
    if(vowel.find(ch) != string::npos) return true;
    return false;
}

int main(){
    while(true){
        cin >> temp;
        if(temp == "end") break;
        ccnt = vcnt = 0;
        bool flag = 0;
        bool include_v = 0;
        for(int i = 0; i < temp.size(); i++){
            char ch = temp[i];
            if(is_vowel(ch)) vcnt++, ccnt = 0, include_v = 1;
            else ccnt++, vcnt = 0;
            if(ccnt == 3 || vcnt == 3) flag = 1;
            if(i > 0 && (ch == temp[i-1]) && (ch != 'e' && ch != 'o')) flag = 1;
        }
        if(include_v == 0) flag = 1;
        if(flag == 1) result.push_back("<" + temp + "> is not acceptable.");
        else result.push_back("<" + temp + "> is acceptable.");
    }
    for(string str : result) cout << str << '\n';
    return 0;
}

// 체크를 여러개의 함수로 나눠서 할 경우 변수공유가 안되어 코드가 길어짐.
// 또한 queue 를 쓴 이전 코드는 실수가 발생하기 쉬움.