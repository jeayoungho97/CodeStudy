#include<bits/stdc++.h>
using namespace std;    
string str; 
int cnt[26]; 			// When declared globally, int array's elements are initialized to 0.
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> str; 		
    for(char a : str){  // for all characters in str
    	cnt[a - 'a']++; // Genius. char - char = int? Yes.
	}
	for(int i = 0; i < 26; i++) cout << cnt[i] << " ";
	return 0; 
}
