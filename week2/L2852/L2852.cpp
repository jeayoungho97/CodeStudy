#include<bits/stdc++.h>
using namespace std;
int result[2], a[101];
int N, t, minute, second, team, points[2];
string str, score_time;
void cmp(){
    if(points[0] > points[1]) result[0] += t;
    else if(points[0] < points[1]) result[1] += t;
    return;
}
void changeToInt(int i, string str){
    a[i] = 60 * atoi(str.substr(0,2).c_str()) + atoi(str.substr(3,2).c_str());
    t = a[i] - a[i-1];
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> team;
        cin >> str;        
        changeToInt(i, str);
        cmp();
        points[team-1]++;
    }
    changeToInt(N+1, "48:00");
    cmp();
    for(int i = 0; i < 2; i++){
        cout << format("{:02}:{:02}", result[i]/60, result[i]%60) << "\n";
    }
    return 0;
}