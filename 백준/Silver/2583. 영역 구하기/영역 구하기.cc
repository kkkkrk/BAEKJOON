#include <bits/stdc++.h>
using namespace std;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int M,N,K;
int S = 1;
bool visited[102][102];
bool R[102][102];
void dfs(int x, int y){
    visited[y][x] = 1;
    for(int i = 0;i < 4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx <0 || nx >= N || ny < 0 || ny >= M) continue;
        if(visited[ny][nx] || R[ny][nx]) continue;
        S += 1;
        dfs(nx, ny);
    }
}

int main(){
    cin >> M >> N >> K;
    int result = 0;
    vector<int> S_v;
    for(int k = 0;k < K;k++){
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for(int i = y1;i < y2;i++){
            for(int j = x1;j < x2;j++){
                R[i][j] = 1;
            }
        }
    }
    for(int i = 0;i < M;i++){
        for(int j = 0;j < N;j++){
          if(visited[i][j] == 0 && R[i][j] == 0) {
              result += 1;
              dfs(j,i);
              S_v.push_back(S);
              S = 1;
          }
        }
    }
    sort(S_v.begin(), S_v.end());
    cout << result << "\n";
    for(int i: S_v){
        cout << i << " ";
    }
    return 0;
}