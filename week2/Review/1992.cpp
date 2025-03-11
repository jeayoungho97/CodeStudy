#include<bits/stdc++.h>
using namespace std;

int N, y, x, ret, Map[65][65];

string quad(int y, int x, int size){
    if(size == 1) return to_string(Map[y][x]);
    for(int i = y; i < y + size; i++){
        for(int j = x; j < x + size; j++){
            if(Map[i][j] != Map[y][x]){
                string quad1 = quad(y, x, size/2);
                string quad2 = quad(y, x + size/2, size/2);
                string quad3 = quad(y + size/2, x, size/2);
                string quad4 = quad(y + size/2, x + size/2, size/2);
                return "(" + quad1 + quad2 + quad3 + quad4 + ")";
            }
        }    
    }
    return to_string(Map[y][x]);
}

int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            scanf("%1d", &Map[i][j]);
        }
    }
    string result = quad(0,0,N);
    // c_str() 안 붙이면 오류발생 --> c style char* != c++ style string
    printf("%s\n", result.c_str());
    return 0;
}