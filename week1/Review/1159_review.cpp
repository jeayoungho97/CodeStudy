#include<bits/stdc++.h>
using namespace std;
int N, cnt[30];
string input[151];
vector<char> result;
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> input[i];
        cnt[input[i][0]-'a']++;
    }
    for(int i = 0; i < 30; i++){
        if(cnt[i] >= 5) result.push_back(i + 'a');
    }
    if(result.size()){
        for(char ch : result) cout << ch;
        cout <<'\n';
    }
    else cout << "PREDAJA";
    return 0;
}