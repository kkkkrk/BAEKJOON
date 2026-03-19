#include <bits/stdc++.h>
using namespace std;
int a[30];
vector<char> result;
int main(){
    string s;
    cin >> s;
    for(char c:s){
        a[c - 'A'] += 1;
    }
    int cnt = 0;
    int chk = -1;
    for(int i = 0;i < 30;i++){
        if(a[i] %2 == 1) {
            chk = i;
            a[i] -= 1;
            cnt++;
        }
    }
    if(cnt >= 2) cout << "I'm Sorry Hansoo";
    else{
        for(int i = 0;i < 30;i++){
            for(int j = 0;j < a[i]/2;j++){
                cout << char(i + 'A');
            }
        }
        if(chk != -1) cout << char(chk + 'A');
        for(int i = 29;i >= 0;i--){
            for(int j = 0;j < a[i]/2;j++){
                cout << char(i + 'A');
            }
        }
    }
    return 0;
}