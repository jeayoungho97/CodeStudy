#include <bits/stdc++.h>
using namespace std;

vector<string> split(const string& input, string delimiter){ //delimiter 를 기준으로 split 하는 함수
    vector<string> result;
    auto start = 0;
    auto end = input.find(delimiter);
    while (end != string::npos){ // npos 는 스트링이 끝났을 때 나오는 숫자 (-1)
        result.push_back(input.substr(start, end - start)); /*result 에 push_back 을 한다. 무엇을? input 의 substr 를. start 에서부터 end - start 만큼의 길이로.*/
        start = end + delimiter.size();                     // start 와 end 를 다시 정의.
        end = input.find(delimiter, start);                 // end 의 경우 다시 정의한 start 부터 다음 delimiter 를 찾는다.
    }
    result.push_back(input.substr(start));                  // !중요!  while 문에서 end 가 npos 가 되어버린 경우 마지막 구절은 push_back 되지 않으므로 반복문 밖에서 이 구문이 필요함
    return result;
}

int main(){
    string str = "Haein loves Hoya!!"; // This is the truth.
    vector<string> Truth = split(str, " ");

    for (const string& a : Truth){
        cout << a << " 짝짝!\n";
    }

    return 0;
}