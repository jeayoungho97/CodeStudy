// 메모리 동적할당 기초
#include<iostream>
#include<algorithm>

int main(){
    int n;
    std::cin >> n;

    int* arr = new int[n];
    for(int i = 0; i < n; i++){
        std::cin >> arr[i];
    }

    int v;
    std::cin >> v;

    int result = std::count(arr, arr + n, v);
    std::cout << result << '\n';

    delete[] arr;
    arr = nullptr;
    
    return 0;
}

// vector 로 하면 아래 와 같음
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int N, v;
    cin >> N;
    vector<int> num(N);
    for(int i = 0; i < N; ++i)
        cin >> num[i];
    cin >> v;
    cout << count(num.begin(), num.end(), v) << '\n';
    return 0;
}