#include<bits/stdc++.h>
using namespace std;

int n = 5;
int r = 3;
int a[] = {1,2,3,4,5};
int main(){
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){         // j = i + 1 이 중요.
            for(int k = j + 1; k < n; k++){
                cout << a[i] << " " << a[j] << " " << a[k] << "\n";
            }
        }
    }
    return 0;
}