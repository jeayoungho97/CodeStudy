#include<bits/stdc++.h>
using namespace std;
// Rules
// a, e, i, o, u 반드시 하나 포함
// 모음 자음 연속 3개 안됨
// 같은 글자 연속 2번 안됨 (ee, oo 는 예외)

string temp;
vector<string> result;
string vowels = "aeiou";

bool is_vowel(char ch){
    if(find(vowels.begin(), vowels.end(), ch) != vowels.end()) return true;
    return false;
}

bool vowel_in_string(string str){
    for(char ch : vowels){
        if(find(str.begin(), str.end(), ch) != str.end()) return true;
    }
    return false;
}

bool three(string str){
    queue<char> q;
    for(char ch : str){
        if(!q.size()) q.push(ch);
        else if(is_vowel(q.front()) == is_vowel(ch)) q.push(ch); // maybe??
        else {
            int size = q.size();
            for(int i = 0; i < size; i++){
                q.pop();
            }
            q.push(ch);
        }
        if(q.size() == 3) return true;
    }
    return false;
}

bool two(string str){
    queue<char> q;
    for(char ch : str){
        if(!q.size()) q.push(ch);
        else if(q.front() == ch){
            if(ch != 'e' && ch != 'o') return true;
        }
        else {
            int size = q.size();
            for(int i = 0; i < size; i++){
                q.pop();
            }
            q.push(ch);
        }
    }
    return false;
}

void solve(string str){
    if(!vowel_in_string(str) || three(str) || two(str)) result.push_back("<" + str + "> is not acceptable.");
    else result.push_back("<" + str + "> is acceptable.");
    return;   
}


int main(){
    while(true){
        cin >> temp;
        if(temp == "end") break;
        solve(temp);
    }
    for(string str : result) cout << str << '\n';
    return 0;
}