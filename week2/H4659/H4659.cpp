    #include<bits/stdc++.h>
    using namespace std;
    string str;
    bool is_vow(char ch){
        set<char> vowels = {'a','e','i','o','u'};
        return vowels.count(ch);
    }
    vector<string> ret;
    void accept(string str){
        queue<char> q;
        string result;
        bool vow_inc = 0;
        int flag = 0;
        for(char ch : str){
            if(is_vow(ch))vow_inc = 1;
            if(q.size()){
                if(is_vow(q.front()) == is_vow(ch)){
                    q.push(ch);
                }
                else{
                    while(q.size()) q.pop();
                    q.push(ch);
                }
            }
            else q.push(ch);
            if(q.size() == 2 && q.front() == q.back()){
                if(q.front() == 'e' || q.front() == 'o') continue;
                else{
                    flag = 1;
                    break;
                } 
            }
            if(q.size() == 3){
                flag = 1;
                break;
            }
        }
        if(vow_inc == 0)flag = 1;
        
        if(flag == 1)ret.push_back("<" + str + "> is not acceptable.");
        else ret.push_back("<" + str + "> is acceptable.");
        return;
    }
    int main(){
        while(true){
            cin >> str;
            if(str == "end"){
                break;
            }
            accept(str);
        }
        for(string i : ret)cout << i << "\n";
        return 0;
    }