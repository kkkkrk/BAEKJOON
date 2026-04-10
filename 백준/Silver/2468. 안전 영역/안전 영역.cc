#include <bits/stdc++.h>
using namespace std;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int main(){
    int N,y,x;
    int mapA[102][102] = {0};
    int result = 0;
    cin >> N;
    for(int i = 0;i < N;i++){
        for(int j = 0;j < N;j++){
            cin >> mapA[i][j];
        }
    }
    for(int maxH = 1;maxH <= 100;maxH++){
        bool mapR[102][102] = {0};
        bool visited[102][102] = {0};
        queue<pair<int,int>> q;
        for(int i = 0;i < N;i++){
            for(int j = 0;j < N;j++){
                if(mapA[i][j] >= maxH) mapR[i][j] = 1;
            }
        }
        int num = 0;
        for(int i = 0;i < N;i++){
            for(int j = 0;j < N;j++){
                if(mapR[i][j] && visited[i][j] == 0){
                    num += 1;
                    visited[i][j] = 1;
                    q.push({i,j});
                    while(q.size()){
                        tie(y,x) = q.front(); q.pop();
                        for(int k = 0;k < 4;k++){
                            int ny = y + dy[k];
                            int nx = x + dx[k];
                            if(ny < 0 || ny >= N || nx <0 || nx >= N || visited[ny][nx] == 1 || mapR[ny][nx] == 0) continue;
                            visited[ny][nx] = 1;
                            q.push({ny,nx});
                        }
                    }
                }
            }
        }
        if(result < num) result = num;
    }
    
    cout << result;
    
    return 0;
}