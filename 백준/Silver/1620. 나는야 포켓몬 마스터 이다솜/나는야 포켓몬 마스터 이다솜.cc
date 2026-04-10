#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    map <string, int> mp1;
    map <int, string> mp2;
    string s;
    int M, N;
    cin >> N >> M;
    for(int i = 1;i <= N;i++){
        cin >> s;
        mp1[s] = i;
        mp2[i] = s;
    }
    for(int i = 0;i < M;i++){
        string s;
        cin >> s;
        if(atoi(s.c_str()) == 0) cout << mp1[s] << "\n";
        else cout << mp2[atoi(s.c_str())] << "\n";
    }

    return 0;
}