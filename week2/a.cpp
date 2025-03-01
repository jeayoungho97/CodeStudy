#include<bits/stdc++.h>
using namespace std;
int result[2], a[100];
int N, t, team, points[2];
string temp, score_time;

void cmp(){
    if(points[0] > points[1]) result[0] += t;
    else if(points[0] < points[1]) result[1] += t;
    return;
}

int main(){
    temp = "01:10";
    points[0]++;
    int minute = atoi(temp.substr(0,2).c_str());
    int second = atoi(temp.substr(3,2).c_str());
    a[0] = 60 * minute + second;
    cout << "t : "<< a[0] <<"\n";
    for(int i : points) cout << i << " ";
    cmp();
    cout << "\n";
    for(int i : result) cout << i << " ";
    cout << "\n";

    temp = "21:10";
    points[1]++;
    minute = atoi(temp.substr(0,2).c_str());
    second = atoi(temp.substr(3,2).c_str());
    t = 60 * minute + second - t;
    cout << "t : "<<t <<"\n";
    for(int i : points) cout << i << " ";
    cmp();
    cout << "\n";
    for(int i : result) cout << i << " ";
    cout << "\n";

    temp = "31:30";
    points[1]++;
    minute = atoi(temp.substr(0,2).c_str());
    second = atoi(temp.substr(3,2).c_str());
    t = 60 * minute + second - t;
    cout << "t : "<<t <<"\n";
    for(int i : points) cout << i << " ";
    cmp();
    cout << "\n";
    for(int i : result) cout << i << " ";
    cout << "\n";

    return 0;
}




    // int size = sizeof(result)/sizeof(result[0]);
    // string str[2];
    // int i =0;
    // for_each(result, result + size, [&str, &i](int &x) {str[i] = format("{:02}:{:02}", x/60, x%60); i++;});
