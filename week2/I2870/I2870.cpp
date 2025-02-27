#include<bits/stdc++.h>
using namespace std;
int N;
string str;
vector<string> result;
bool cmp(string a, string b){
    if(a.length() == b.length()) return a < b;
    return a.length() < b.length();
}
int main(){
    cin >> N;
    while(N--){
        string ret = "";
        // 처음에 ret 을 string 이 아닌 int 나 long long 으로 계산했더니... 엄청 큰 숫자를 처리를 못했다.
        cin >> str;
        for(char ch : str){
            if(ch >= '0' && ch <= '9'){
                if(ret == "" || ret == "0"){
                    ret = ch;
                }
                else{
                    ret += ch;
                }
            }
            else{
                if(ret != ""){
                    result.push_back(ret);
                    ret = "";
                }
            }
        }
        if(ret != ""){
            result.push_back(ret);
        }
    }
    sort(result.begin(),result.end(),cmp);
    for(string i : result)cout << i << "\n";
    return 0;
}