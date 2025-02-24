#include<bits/stdc++.h>
using namespace std;    
string str; 
int cnt[26]; 			// When declared globally, int array's elements are initialized to 0.
int main(){
    for(char a : str){  // for all characters in str
    	cnt[a - 'a']++; // char as an index of array = ASCII number
	}
	for(int i = 0; i < 26; i++) cout << cnt[i] << " ";
	return 0; 
}
