#include<bits/stdc++.h>
using namespace std;
int N;
int arr[101][101];

void split(int y, int x, int size){
    if(size == 1){
        printf("%d", arr[y][x]);
        return;
    }
    int check = arr[y][x];
    for(int i = y; i < y + size; i++){
        for(int j = x; j < x + size; j++){
            if(check != arr[i][j]){
                printf("(");
                split(y,x,size/2);
                split(y,x+size/2,size/2);
                split(y+size/2,x,size/2);
                split(y+size/2,x+size/2,size/2);
                printf(")");
                return;
            }
        }
    }
    printf("%d", check);
    return;
}

int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
           scanf("%1d", &arr[i][j]);
        }
    }
    split(0,0,N);

    return 0;
}