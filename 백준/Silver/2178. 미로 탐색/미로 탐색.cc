#include <bits/stdc++.h>
using namespace std;
const int max_n = 104;
int dx[4]  = {1,0,-1,0};
int dy[4]  = {0,1,0,-1};
int N, M, a[max_n][max_n], visited[max_n][max_n],y,x;

int main()
{
    cin >> N >> M;
    for(int i = 0;i < N;i++){
        for(int j = 0;j < M;j++){
            scanf("%1d", &a[i][j]);
        }
    }
    queue <pair<int, int>> q;
    q.push({0,0});
    visited[0][0] = 1;
    
    while(q.size()){
        tie(y, x) = q.front(); q.pop();
        for(int i = 0;i < 4;i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >= N || nx < 0 || nx >= M || visited[ny][nx] || a[ny][nx] == 0) continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});
            
        }
    }
    cout << visited[N-1][M-1];
    
    
    return 0;
}
