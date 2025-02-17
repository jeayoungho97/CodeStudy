#include<bits/stdc++.h>
using namespace std;

void printV(const vector<int> &v){                  // input에 &가 붙는 것은 벡터를 복사하지 않고 원본을 직접 참조하겠다는 뜻. const는 vector 원본을 변경시키지 않겠다는 뜻.
    for(int i : v){
        cout << i << " ";
    }
    cout << "\n";
}                                                 

int main(){
    array<int, 3> a = {2,3,1};
    vector<int> v;
    for(int i = 0; i<a.size(); i++)v.push_back(a[i]);  //vector v에 a의 값을 pushback
    cout << "오름차순 정렬되지 않은 수열\n";
    do{
        printV(v);                                      // 단순하게 print 이지만 나중에 logic 넣을 수 있음.
    }while(next_permutation(v.begin(),v.end()));        // next_permutation 으로 직접 v의 순열을 만듦. 
    cout << "--------------\n";

    v.clear();
    sort(a.begin(),a.end());
    for(int i = 0; i<a.size(); i++)v.push_back(a[i]);
    cout << "오름차순 정렬된 수열\n";
    do{
        printV(v);
    }while(next_permutation(v.begin(),v.end()));        // next_permutation 의 결과는 boolean (새로운 수열이 이전 순열보다 사전적으로 큰 경우 1, 마지막에 0)

    return 0;
}