#include<bits/stdc++.h>
using namespace std;

int N, M, J, cnt, apple_position, basket_left = 1, basket_right;

void solve(int pos){
    basket_right = basket_left + (M - 1);
    if(pos >= basket_left && pos <= basket_right) return;
    else if(pos < basket_left){
        cnt += (basket_left - pos);
        basket_left = pos;
        basket_right = basket_left + (M -1);
        return;
    }
    else{
        cnt += (pos - basket_right);
        basket_right = pos;
        basket_left = basket_right - (M - 1);
        return;
    }
}

int main(){
    cin >> N >> M;
    cin >> J;
    while(J--){
        cin >> apple_position;
        solve(apple_position);
    }
    cout << cnt << '\n';
    return 0;
}