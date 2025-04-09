#include <iostream>
#include <string>
#include <algorithm>

int main(){
    int a, b, c;
    std::cin >> a >> b >> c;

    std::string result = std::to_string(a * b * c);

    for(int i = 0; i < 10; i++){
        std::cout << std::count(result.begin(), result.end(), i + '0') << '\n';
    }

    return 0;
}