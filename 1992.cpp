#include <bits/stdc++.h>
using namespace std;
bool inp[65][65];

void t(int N, int y, int x){
    if(N == 1) {
        cout << inp[y][x];
    }
    else{
        bool chk = inp[y][x];
        bool flag = 0;
        for(int i = y;i < y + N;i++){
            for(int j = x;j < x + N;j++){
                if(inp[i][j] != chk) {
                    flag = 1;
                    break;
                }
            }
            if(flag) break;
        }
        if(flag){
            cout << "(";
            t(N/2, y, x);
            t(N/2, y, x + N/2);
            t(N/2, y + N/2, x);
            t(N/2, y + N/2, x + N/2);
            cout << ")";
        }
        else{
            cout << inp[y][x];
        }
    }
}

int main(){
    int N,temp;
    cin >> N;
    for(int i = 0;i < N;i++){
        for(int j = 0;j < N;j++){
            if(scanf("%1d", &temp) == 1){
                inp[i][j] = (temp != 0);
            }
        }
    }
    t(N, 0, 0);
    return 0;
}