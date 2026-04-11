#include <bits/stdc++.h>
using namespace std;
int R,C,K, ret;
int dy[] = {0,1,0,-1};
int dx[] = {1,0,-1,0};
bool a[6][6], visited[6][6];
void dfs(int y, int x, int cnt){
    if(y == 0 && x == C-1){
        if(cnt == K) ret += 1;
        return;
    }
    for(int i = 0;i < 4;i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= R || nx < 0 || nx >= C || a[ny][nx] || visited[ny][nx]) continue;
        visited[ny][nx] = 1;
        dfs(ny,nx,cnt + 1);
        visited[ny][nx] = 0;
    }
}
int main(){
    cin >> R >> C >> K;
    for(int i = 0;i < R;i++){
        string s;
        cin >> s;
        for(int j = 0;j < C;j++){
            if(s[j] == 'T') a[i][j] = 1;
        }
    }
    visited[R-1][0] = 1;
    dfs(R-1,0,1);
    cout << ret;
    return 0;
}