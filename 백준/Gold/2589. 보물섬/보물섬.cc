#include <bits/stdc++.h>
using namespace std;
int N, M, ret, y, x;
string inp;
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
bool a[52][52];
int visited[52][52];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for(int i = 0;i < N;i++){
        cin >> inp;
        for(int j = 0;j < M;j++){
            if(inp[j] == 'L') a[i][j] = 1;
            else a[i][j] = 0;
        }
    }
    // for(int i = 0;i < N;i++){
    //     for(int j = 0;j < M;j++){
    //         cout << a[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    queue<pair<int,int>> q;
    for(int i = 0;i < N;i++){
        for(int j = 0;j < M;j++){
            if(a[i][j]){
                memset(visited, 0, sizeof(visited));
                q.push({i,j});
                visited[i][j] = 1;
                while(q.size()){
                    tie(y,x) = q.front(); q.pop();
                    for(int k = 0;k < 4;k++){
                        int ny = y + dy[k];
                        int nx = x + dx[k];
                        if(ny < 0 || ny >= N || nx < 0 || nx >= M || a[ny][nx] == 0) continue;
                        if(visited[ny][nx]) continue;
                        q.push({ny, nx});
                        ret = max(ret, visited[y][x]);
                        visited[ny][nx] = visited[y][x] + 1;
                    }
                }
            }
        }
    }
    cout << ret;
    
    return 0;
}