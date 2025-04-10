#include <iostream>
#include <algorithm>

int main(){
    int idx, arr[9], result = 0;
    for (int i = 0; i < 9; ++i) {
        std::cin >> arr[i];
        if(result < arr[i]){
            result = arr[i];
            idx = i + 1;
        }
    }

    std::cout << result << '\n';
    std::cout << idx << '\n';
    return 0;
}