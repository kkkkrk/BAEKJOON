#include <bits/stdc++.h>
using namespace std;
const int max_N = 102;
bool cheeze[max_N][max_N];
bool visited[max_N][max_N];
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
int M,N,y,x, time_c, size_c;
vector<pair<int,int>> v;

int main(){
    queue<pair<int,int>> q;
    cin >> M >> N;
    for(int i = 0;i < M;i++){
        for(int j = 0;j < N;j++){
            cin >> cheeze[i][j];
        }
    }
    while(1){
        for(int i = 0;i < M;i++){
            for(int j = 0;j <N;j++){
                visited[i][j] = 0;
            }
        }
        visited[0][0] = 1;
        q.push({0,0});
        while(q.size()){
            tie(y,x) = q.front(); q.pop();
            for(int i = 0;i < 4;i++){
                int ny = y + dy[i];
                int nx = x + dx[i];
                if(ny < 0 || ny >= M || nx < 0 || nx >= N || visited[ny][nx]) continue;
                if(cheeze[ny][nx] == 0){
                    visited[ny][nx] = 1;
                    q.push({ny, nx});                
                }
                else if(cheeze[ny][nx] == 1){
                    visited[ny][nx] = 1;
                    v.push_back({ny, nx});
                }
            }
        }
        time_c += 1;
        if(v.size()){
            size_c = v.size();
            // cout << "time: " << time_c << " size: " << size_c << "\n";
            for(auto it:v){
                // cout << "(" << it.first << "," << it.second << ") ";
                cheeze[it.first][it.second] = 0;
            }
            v.clear();
        }
        else{
            break;
        }
    }
    cout << time_c -1 << "\n" << size_c;
    return 0;
}