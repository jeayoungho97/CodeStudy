#include <bits/stdc++.h>
using namespace std;

string input;
map<char, int> words;
int cntodds;
char odd;
vector<char> result;

int main(){
    cin >> input;
    for(char ch : input){
        words[ch]++;
    }
    for(auto i : words){
        if(i.second % 2 == 1){
            odd = i.first;
            cntodds++;
        }
    }
    if(cntodds > 1){
        cout << "I\'m Sorry Hansoo\n";
        exit(0);
    }
    else{
        for(auto i : words){
            for(int j = 0; j < i.second/2; j++){
                result.push_back(i.first);
            }
        }
    }
    vector<char> rev_result(result.size());
    reverse_copy(result.begin(), result.end(), rev_result.begin());


    for(char ch : result)cout << ch;
    cout << "\n";
    for(char ch : rev_result)cout << ch;
    cout << "\n";

    return 0;
}