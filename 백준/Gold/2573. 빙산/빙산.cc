#include <bits/stdc++.h>
using namespace std;
int y, x, N, M, a[301][301], sum;
bool visited[301][301];
int dy[] = {0,1,0,-1};
int dx[] = {1,0,-1,0};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    queue<pair<int,int>> q;
    cin >> N >> M;
    for(int i = 0;i < N;i++){
        for(int j = 0;j < M;j++){
            cin >> a[i][j];
            if(a[i][j]) sum += 1;
        }
    }
    tie(y,x) = q.front();
    for(int cnt = 0; cnt < 1000;cnt++){
        memset(visited, 0, sizeof(visited));
        int flag = 0;
        for(int i = 0;i < N;i++){
            for(int j = 0;j< M;j++){
                if(a[i][j]){
                    q.push({i,j});
                    visited[i][j] = 1;
                    flag = 1;
                    break;
                }
            }
            if(flag) break;
        }
        if(!q.size()) break;
        int cmpS = 0;
        int nextS = sum;
        while(q.size()){
            tie(y,x) = q.front(); q.pop();
            cmpS += 1;
            for(int k = 0;k < 4;k++){
                int ny = y + dy[k];
                int nx = x + dx[k];
                if(ny < 0 || ny >= N || nx < 0 || nx >= M ||visited[ny][nx]) continue;
                if(a[ny][nx] == 0){
                    a[y][x] -= 1;
                }
                else{
                    visited[ny][nx] = 1;
                    q.push({ny,nx}); 
                }
            }
            if(a[y][x] <= 0){
                nextS -= 1;
                a[y][x] = 0;
            }
        }
        if(cmpS != sum){
            cout << cnt;
            return 0;
        }
        sum = nextS;
    }
    cout << 0;

    return 0;
}