#include<bits/stdc++.h>
using namespace std;
int a,b,c,cnt[100],fee,x,y;     //cnt counts current number of cars
int main(){
    cin >> a >> b >> c;
    for(int i = 0; i < 3; i++){
        cin >> x >> y;
        for(int j = x; j < y; j++)cnt[j]++; // MAIN LOGIC : from minute x to y, the car pays fee from x to y-1. So I need to count the cars by minute.
    }
    for(int i : cnt){
        if(i){
            if(i == 1)fee += a;
            else if(i == 2)fee += 2 * b;
            else if(i == 3) fee += 3 * c;
        }
    }
    cout << fee << "\n";
    return 0;
}