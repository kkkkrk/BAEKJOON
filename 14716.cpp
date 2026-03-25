#include <bits/stdc++.h>
using namespace std;
int hsm[252][252];
int visited[252][252];
int M, N, result,y,x;
int dx[] = {1,1,1,-1,-1,-1,0,0};
int dy[] = {1,0,-1,1,0,-1,1,-1};
int main()
{
    cin >> M >> N;
    for(int i = 0;i < M;i++){
        for(int j = 0;j < N;j++){
            cin >> hsm[i][j];
        }
    }
    
    for(int i = 0;i < M;i++){
        for(int j = 0;j < N;j++){
            if(hsm[i][j] && !visited[i][j]){
                result += 1;
                // cout << "i: " << i << " j: " << j << "\n";
                queue<pair<int,int>> q;
                q.push({i,j});
                while(q.size()){
                    tie(y,x) = q.front(); q.pop();
                    for(int k = 0;k < 8;k++){
                        int ny = y + dy[k];
                        int nx = x + dx[k];
                        if(nx < 0 || nx >= N || ny < 0 || ny >= M || visited[ny][nx] || hsm[ny][nx] == 0) continue;
                        visited[ny][nx] = visited[y][x] + 1;
                        q.push({ny, nx});
                    }
                }
            }
        }
    }
    cout << result;
    
    return 0;
}