#include <bits/stdc++.h>
using namespace std;
string input;

// map 에서는 key 가 자동으로 알파벳 순으로 정렬이 됨.
map<char, int> words;        

int cntodds;
char odd = '\0';
vector<char> result;
int main(){
    cin >> input;
    for(char ch : input)words[ch]++;
    for(auto i : words){
        
        // bitwise and (&) -> if 1, odd. if 0, even.
        if(i.second & 1){           
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
    // Currently result is half the palindrome.
    vector<char> rev_result(result.size());

    // So we make the other half but reverse it.
    reverse_copy(result.begin(), result.end(), rev_result.begin());

    // If there is a off number alphabet, put it in the middle.
    result.push_back(odd);

    // Add the two halves to make the palindrome!
    result.insert(result.end(), rev_result.begin(), rev_result.end());

    for(char ch : result)cout << ch;

    cout << "\n";

    return 0;
}