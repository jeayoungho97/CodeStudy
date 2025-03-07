#include<bits/stdc++.h>
using namespace std;
string input;
void ROT13(string &str){
    for(char &ch : str){
        if(ch >= 'a' && ch <= 'z'){
            if(ch + 13 > 'z') ch -= 13;
            else ch += 13;
        }
        if(ch >= 'A' && ch <= 'Z'){
            if(ch + 13 > 'Z') ch-= 13;
            else ch += 13;
        }
    }
}
int main(){
    getline(cin, input);
    ROT13(input);
    cout << input << '\n';
    return 0;
}