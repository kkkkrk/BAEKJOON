#include <bits/stdc++.h>
using namespace std;
const int max_N = 9;
int N, M, y, x;
int result = 0;
int visited[max_N][max_N];
int virus[max_N][max_N];
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> N >> M;
    for(int i = 0;i < N;i++){
        for(int j = 0;j < M;j++){
            cin >> virus[i][j];
        }
    }
    for(int i1 = 0;i1 < N;i1++){
        for(int j1 = 0;j1 < M;j1++){
            if(virus[i1][j1] != 0) continue;
            for(int i2 = 0;i2 < N;i2++){
                for(int j2 = 0;j2 < M;j2++){
                    if(i1 == i2 && j1 == j2) continue;
                    if(virus[i2][j2] != 0) continue;
                    for(int i3 = 0;i3 < N;i3++){
                        for(int j3 = 0;j3 < M;j3++){
                            if(i1 == i3 && j1 == j3) continue;
                            if(i2 == i3 && j2 == j3) continue;
                            if(virus[i3][j3] != 0) continue;
                            int copy[max_N][max_N];
                            for(int i = 0;i < N;i++){
                                for(int j = 0;j < M;j++){
                                    copy[i][j] = virus[i][j];
                                }
                            }
                            copy[i1][j1] = 1;
                            copy[i2][j2] = 1;
                            copy[i3][j3] = 1;
                            for(int i = 0;i < N;i++){
                                for(int j = 0;j < M;j++){
                                    if(copy[i][j] == 2){
                                        queue<pair<int,int>> q;
                                        q.push({i,j});
                                        while(q.size()){
                                            tie(y,x) = q.front(); q.pop();
                                            for(int k = 0;k < 4;k++){
                                                int ny = y + dy[k];
                                                int nx = x + dx[k];
                                                if(ny < 0 || ny >= N || nx < 0 || nx >= M || copy[ny][nx] != 0) continue;
                                                copy[ny][nx] = 2;
                                                q.push({ny, nx});
                                            }
                                        }
                                    }
                                }
                            }
                            int cnt = 0;
                            for(int i = 0;i < N;i++){
                                for(int j = 0;j < M;j++){
                                    if(copy[i][j] == 0) cnt += 1;
                                }
                            }
                            if(result < cnt) result = cnt;
                        }
                    }
                }
            }
        }
    }
    cout << result;

    return 0;
}