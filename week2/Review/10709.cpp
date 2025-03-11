#include<bits/stdc++.h>
using namespace std;

int H, W, Start, End, result[104][104];
string input[104];
int main(){
    cin >> H >> W;
    for(int i = 0; i < H; i++){
        cin >> input[i];
    }
    for(int i = 0; i < H; i++){
        End = input[i].find('c');
        if(End == string::npos){
            for(int j = 0; j < W; j++) result[i][j] = -1;
            continue;
        } 
        for(int j = 0; j < End; j++){
        result[i][j] = -1;
        }
        while(true){
            Start = End;
            End = input[i].find('c', Start + 1);
            if(End == string::npos){
                for(int j = 0; j < W - Start; j++){
                    result[i][Start + j] = j;
                }
                break;
            }
            else{
                for(int j = 0; j < End - Start; j++){
                    result[i][Start + j] = j;
                }
            }
        }
    }
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cout << result[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}