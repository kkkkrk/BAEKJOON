#include <bits/stdc++.h>
using namespace std;
int a[103];
int main(){
    int M, N;
    cin >> M >> N;
    for(int i = 0;i < N;i++){
        int q,w,e;
        cin >> q >> w >> e;
        for(int j = q;j <= w;j++){
            a[j] = e;
        }
    }
    for(int i = 1;i <= M;i++){
        cout << a[i] << ' ';
    }

    return 0;
}