#include<bits/stdc++.h>
using namespace std;

int a[26];
string input, ret;
char mid = 0;

int main(){
    cin >> input;
    for(char ch : input){
        a[ch - 'A']++;
    }

    vector<char> left, right;

    for(int i = 0; i < 26; i++){
        if(a[i]){
            if(a[i] % 2 == 1){
                if(mid){
                    cout << "I\'m Sorry Hansoo" << '\n';
                    return 0;
                }
                mid = i + 'A';
            }
            for(int j = 0; j < a[i]/2; j++){
                left.push_back(i + 'A');
            }
        }
    }
    right = left;
    reverse(right.begin(), right.end());

    for(char ch : left) ret += ch;
    if(mid) ret += mid;
    for(char ch : right) ret += ch;
    cout << ret << '\n';

    return 0;
}