#include<bits/stdc++.h>
using namespace std;

// swap 을 이용한 Permutation 구현

int a[] = {1,2,3};
int n = 3, r = 3;

void print(){
    for(int i = 0; i < r; i++){
        cout << a[i] << " ";
    }
    cout << "\n";
}

void makePermutation(int n, int r, int depth){
    if(r == depth){
        print(); // when r == depth, print all elements of a
        return;
    }
    for(int i = depth; i < n; i++){
        swap(a[depth], a[i]);             // swap 을 통해 
        makePermutation(n, r, depth + 1); // depth 를 하나씩 늘려가며 recursion 이 일어남. 이 때, 정해진 r 값과 depth 가 같아지면 return, 다시 swap.
        swap(a[depth], a[i]);             // recursion 을 통해 모든 경우의 수를 다 살펴볼 수 있음을 알아내야할 듯.
    }
    return;
}

int main(){
    makePermutation(n, r, 0);
    return 0;
}