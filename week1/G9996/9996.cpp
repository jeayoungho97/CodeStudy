#include <bits/stdc++.h>
using namespace std;

int N;
string pat, fr, en, input;
vector<string> result;

int main(){
    cin >> N >> pat;
    auto start = 0;
    auto end = pat.find("*");
    
    fr = pat.substr(start, end-start); //front letters

    start = end + 1;                   // Wrong when I wrote ( start = end + size("*") ) ----> size("*") == 2 OMG this took so long to find
    end = string::npos;

    en = pat.substr(start);            //end letters

    for(int i = 0; i < N; i++){
        cin >> input;
        if(input.length() < (fr.length() + en.length())){ // Why you need this : 1, in*ner, iner -> DA      NO!
            result.push_back("NE\n");
            continue;
        }
        else if(fr != input.substr(0, fr.length()) || en != input.substr(input.length() - en.length(), en.length())){
            result.push_back("NE\n");
            continue;
        }
        else{
            result.push_back("DA\n");
            continue;
        }
    }

    for(string str : result)cout << str;

    return 0;
}