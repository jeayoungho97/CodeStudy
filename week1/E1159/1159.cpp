#include<bits/stdc++.h>
using namespace std;
int length, check;
map<char, int> mp;
string str;

int main(){
    cin >> length;
    for(int i = 0; i < length; i++){
        cin >> str;
        mp[str[0]]++;
    }

    // key : value -> value 값이 5이상인 것이 있다면, 그것들의 key 를 띄어쓰기 없이 cout
    // value 값이 모두 5 미만이라면, PREDAJA 출력

    for(auto it = mp.begin(); it != mp.end(); it++){
        if((*it).second >= 5){
            cout << (*it).first;
            check = 1;
        }
    }
    if(check == 0){
        cout << "PREDAJA\n";
    }
    return 0;
}