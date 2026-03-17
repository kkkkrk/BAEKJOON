#include <bits/stdc++.h>
using namespace std;
int main(){
    int N;
    map<char, int> mp;
    cin >> N;
    for(int i = 0;i < N;i++){
        string s;
        cin >> s;
        mp[s[0]] += 1;
    }
    int flag = 1;
    for(auto it: mp){
        if(it.second >= 5) {
            cout << it.first;
            flag = 0;
        }
    }
    if(flag) cout << "PREDAJA";
    
    
    
    return 0;
}