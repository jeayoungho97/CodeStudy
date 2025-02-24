#include <bits/stdc++.h>
using namespace std;

int N;
string pat, front, back, input;
vector<string> result;

int main(){
    cin >> N >> pat;
    int end = pat.find("*");
    
    front = pat.substr(0, end); //front letters

    back = pat.substr(end + 1); //end letters

    for(int i = 0; i < N; i++){
        cin >> input;
        // Why you need this : 1, in*ner, iner -> DA      NO!
        if(input.length() < (front.length() + back.length())){ 
            result.push_back("NE\n");
            continue;
        }
        else if(front != input.substr(0, front.length()) || back != input.substr(input.length() - back.length(), back.length())){
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