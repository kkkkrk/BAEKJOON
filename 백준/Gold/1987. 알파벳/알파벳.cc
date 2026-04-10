#include <bits/stdc++.h>
using namespace std;
int R, C, y, x;
int ret = 1;
int a[21][21];
int visited[21][21];
bool alpha[30];
int dy[] = {0,1,0,-1};
int dx[] = {1,0,-1,0};
void dfs(int y, int x){
    for(int i = 0;i < 4;i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= R || nx < 0 || nx >= C || visited[ny][nx]) continue;
        if(alpha[a[ny][nx]]) continue;
        visited[ny][nx] = visited[y][x] + 1;
        ret = max(ret, visited[ny][nx]);
        alpha[a[ny][nx]] = 1;
        dfs(ny, nx);
        alpha[a[ny][nx]] = 0;
        visited[ny][nx] = 0;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> R >> C;
    for(int i = 0;i < R;i++){
        string s;
        cin >> s;
        for(int j = 0;j < C;j++){
            a[i][j] = int(s[j] - 'A');
        }
    }
    alpha[a[0][0]] = 1;
    visited[0][0] = 1;
    dfs(0,0);
    cout << ret;
    return 0;
}