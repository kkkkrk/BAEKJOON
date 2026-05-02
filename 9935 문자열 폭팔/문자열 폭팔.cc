#include <bits/stdc++.h>
using namespace std;

int main(){
    string s, boom;
    bool flag;
    deque<char> dq;
    cin >> s >> boom;
    int boomS = boom.size();
    for(char c : s){
        dq.push_back(c);
        if(dq.size() > boomS){
            flag = 1;
            int dqS = dq.size();
            for(int i = 0;i < boomS;i++){
                if(boom[i] != dq[dqS - boomS + i]){
                    flag = 0;
                    break;
                }
            }
            if(flag){
                for(int i = 0;i < boomS;i++){
                    dq.pop_back();
                }
            }
        }
        cout << c << ": ";
        for(auto it: dq){
            cout << it;
        }
        cout << "\n";
    }
    if(dq.size()){
        for(int i = 0;i < dq.size();i++){
            cout << dq[i];
        }
    }
    else{
        cout << "FRULA";
    }
    return 0;
}
