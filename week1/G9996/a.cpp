#include <bits/stdc++.h>
using namespace std;
string input, pat;
string fr, en;

int main(){
    cin >> pat;
    auto start = 0;
    auto end = pat.find("*");
    
    fr = pat.substr(start, end-start); //front letters

    start = end + 1;
    
    en = pat.substr(start);            //end letters

    cin >> input;

    if(input.length() < fr.length() + en.length()){
        cout << input.length() << fr.length() << en.length() << en << size("the") << "Right\n";
        
    }
    else cout << input.length() << fr.length() << en.length() << size("*") << en << "Wrong\n";
    return 0;
}