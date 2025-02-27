#include<bits/stdc++.h>
using namespace std;
int n, m, apple, apples, basket_left, basket_right, cnt;
int main(){
    cin >> n >> m;
    basket_left = 1;
    basket_right = m;                       // 바구니의 길이에 따라 잘 계산하자...
    cin >> apples;
    while(apples--){
        cin >> apple;
        if(apple > basket_right){
            cnt += (apple - basket_right);
            basket_right = apple;
            basket_left = apple - m + 1;    // 맞왜틀이었으나 길이가 3이라면 2를 빼주는게 맞다는 것을 뒤늦게 알아챘다.
        }
        else if(apple < basket_left){
            cnt += (basket_left - apple);
            basket_left = apple;
            basket_right = apple + m - 1;
        }
    }
    cout << cnt << "\n";
    return 0;
}
