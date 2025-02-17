#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[] = {1,2,3};
    int sum = accumulate(a,a+3,0);
    cout << sum << "\n";
    return 0;
}