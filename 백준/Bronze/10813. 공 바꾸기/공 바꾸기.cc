#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,M,a[105];
    cin >> N >> M;
    for(int i = 1;i <=N;i++){
        a[i] = i;
    }
    for(int i = 0;i <M;i++){
        int x,y;
        cin >> x >> y;
        swap(a[x],a[y]);
    }
    for(int i = 1;i <=N;i++){
        cout << a[i] << ' ';
    }
    return 0;
}