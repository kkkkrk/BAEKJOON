#include <bits/stdc++.h>
using namespace std;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int main(){
    int N, M, K, T,y,x;
    cin >> T;
    vector<int> result;
    for(int t = 0;t < T;t++){
        bool visited[51][51] = {0};
        bool mapB[51][51] = {0};
        queue<pair<int,int>> q;
        int num = 0;
        cin >> N >> M >> K;
        for(int i = 0;i < K;i++){
            int a,b;
            cin >> a >> b;
            mapB[a][b] = 1;
        }
        
        for(int i = 0;i < N;i++){
            for(int j = 0;j < M;j++){
                if(mapB[i][j] && !visited[i][j]){
                    num += 1;
                    visited[i][j] = 1;
                    q.push({i,j});
                    while(q.size()){
                        tie(y,x) = q.front(); q.pop();
                        for(int k = 0;k < 4;k++){
                            int ny = y + dy[k];
                            int nx = x + dx[k];
                            if(ny < 0 || ny >=N || nx <0 || nx >= M || visited[ny][nx] == 1 || mapB[ny][nx] == 0) continue;
                            visited[ny][nx] = 1;
                            q.push({ny,nx});
                        }
                    }
                }
            }
        }
        result.push_back(num);
    }
    
    for(int i: result){
            cout << i << "\n";
        }
    
    return 0;
}