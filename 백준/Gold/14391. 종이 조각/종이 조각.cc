#include <bits/stdc++.h>
using namespace std;
int rett, N, M, a[5][5], yy,xx;
bool visited[5][5];
void go(int y, int x, int ret){
    rett = max(ret, rett);
    int nextY, nextX;
    if(x == M-1){
        if(y == N-1){
            if(!visited[y][x]) rett = max(rett,ret + a[y][x]);
            return;
        }
        else{
            nextX = 0;
            nextY = y + 1;
        }
    }
    else{
        nextX = x + 1;
        nextY = y;
    }
    if(visited[y][x]) {
        go(nextY, nextX,ret);
        return;
    }
    go(nextY, nextX,ret);
    int cmpR = a[y][x];
    visited[y][x] = 1;
    go(nextY, nextX, ret + cmpR);
    int flag = 0;
    for(int i = 1;i < M - x;i++){
        cmpR = a[y][x];
        queue<pair<int,int>> q;
        for(int j = x + 1;j <= x+i;j++){
            if(visited[y][j]){
                break;
                flag = 1;
            }
            visited[y][j] = 1;
            q.push({y,j});
            cmpR = (cmpR*10) + a[y][j];
        }
        go(nextY, nextX, ret + cmpR);
        while(q.size()){
            tie(yy,xx) = q.front(); q.pop();
            visited[yy][xx] = 0;
        }
        if(flag) break;
    }
    flag = 0;
    for(int i = 1;i < N - y;i++){
        cmpR = a[y][x];
        queue<pair<int,int>> q;
        for(int j = y + 1;j <= y+i;j++){
            if(visited[j][x]){
                break;
                flag = 1;
            }
            visited[j][x] = 1;
            q.push({j,x});
            cmpR = (cmpR*10) + a[j][x];
        }
        go(nextY, nextX, ret + cmpR);
        while(q.size()){
            tie(yy,xx) = q.front(); q.pop();
            visited[yy][xx] = 0;
        }
        if(flag) break;
    }
    visited[y][x] = 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for(int i = 0;i < N;i++){
        int inp;
        cin >> inp;
        for(int j = M-1;j >= 0;j--){
            a[i][j] = inp % 10;
            inp /= 10;
        }
    }
    go(0,0,0);
    cout << rett;
    return 0;
}