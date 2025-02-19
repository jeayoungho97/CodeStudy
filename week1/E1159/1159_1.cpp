#include<bits/stdc++.h>
using namespace std; 
int n, cnt[26];                                                // cnt seems to be useful for alphabetical problems (cnt[26])
string s, ret; 
int main(){
    cin >> n; 
    for(int i = 0; i < n; i++){
        cin >> s; 
        cnt[s[0] - 'a']++;                                     // Genius again! 난 왜 이 생각을 못했을까?
    }
    for(int i = 0; i < 26; i++)if(cnt[i] >= 5) ret+=  i + 'a'; // changes int into char if >= 5 and stores it in ret
    if(ret.size()) cout << ret << "\n";                        // if ret has an element, print it
    else cout << "PREDAJA" << "\n";                            // if ret has no element, print PREDAJA
}