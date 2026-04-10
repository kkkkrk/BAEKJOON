#include <bits/stdc++.h>
using namespace std;
int N, M, y, x, yy, xx, yyy, xxx;
bool vvisited[1502][1502];
bool visited[1502][1502];
bool a[1502][1502];
int dy[] = {0,1,0,-1};
int dx[] = {1,0,-1,0};
int main(){
    string s;
    queue<pair<int,int>> q;
    queue<pair<int,int>> qq;
    queue<pair<int,int>> endq;
    queue<pair<int,int>> endqq;
    cin >> N >> M;
    int flag = 1;
    for(int i = 0;i < N;i++){
        cin >> s;
        for(int j = 0;j < M;j++){
            if(s[j] == 'X'){
                a[i][j] = 1;
            }
            else if(s[j] == '.'){
                q.push({i,j});
                vvisited[i][j] = 1;
            }
            else if(s[j] == 'L'){
                q.push({i,j});
                vvisited[i][j] = 1;
                if(flag){
                    endq.push({i,j});
                    visited[i][j] = 1;
                    flag = 0;
                }
                else{
                    yy = i;
                    xx = j;
                }
            }
        }
    }
    for(int cnt = 0;cnt <= 5000;cnt++){
        while(endq.size()){
            tie(y,x) = endq.front(); endq.pop();
            for(int i = 0;i < 4;i++){
                int ny = y + dy[i];
                int nx = x + dx[i];
                if(ny < 0 || ny >= N || nx < 0 || nx >= M || visited[ny][nx] ) continue;
                if(ny == yy && nx == xx){
                    cout << cnt;
                    return 0;
                }
                else if(a[ny][nx] == 1){
                    endqq.push({ny, nx});
                    visited[ny][nx] = 1;
                }
                else if(a[ny][nx] == 0){
                    endq.push({ny, nx});
                    visited[ny][nx] = 1;
                }
            }
        }
        while(endqq.size()){
            endq.push(endqq.front());
            endqq.pop();
        }
        while(q.size()){
            tie(y,x) = q.front(); q.pop();
            for(int i = 0;i < 4;i++){
                int ny = y + dy[i];
                int nx = x + dx[i];
                if(ny < 0 || ny >= N || nx < 0 || nx >= M || vvisited[ny][nx] ) continue;
                if(a[ny][nx] == 1){
                    qq.push({ny, nx});
                    vvisited[ny][nx] = 1;
                }
            }
        }
        while(qq.size()){
            tie(y,x) = qq.front();
            q.push({y,x});
            a[y][x] = 0;
            qq.pop();
        }
    }

    return 0;
}