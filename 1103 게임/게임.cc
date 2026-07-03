#include <iostream>
#include <string>
using namespace std;
int N, M, v[52][52], a[52][52], biggest, ret;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
void go(int y, int x){
    // cout << y << ' ' << x << '\n';
    for(int k = 0;k < 4;k++){
        int ny = y + v[y][x] * dy[k];
        int nx = x + v[y][x] * dx[k];
        if(ny < 0 || ny >= N || nx < 0 || nx >= M || v[ny][nx] == -1 || a[y][x] > biggest || a[ny][nx] > a[y][x]) continue;
        a[ny][nx] = a[y][x] + 1;
        go(ny, nx);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    for(int i = 0;i < N;i++){
        string inp;
        cin >> inp;
        for(int j = 0;j < M;j++){
            if(inp[j] == 'H') v[i][j] = -1;
            else v[i][j] = inp[j] - '0';
        }
    }
    biggest = N*M + 3;
    go(0,0);
    for(int i = 0;i < N;i++){
        for(int j = 0;j < M;j++){
            ret = max(ret, a[i][j]);
        }
    }
    if(ret > N*M) cout << -1;
    else cout << ret + 1;
    
    return 0;
}
