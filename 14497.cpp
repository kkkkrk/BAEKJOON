#include <bits/stdc++.h>
using namespace std;
int N, M, y, x, xx,xxx,yy,yyy;
int visited[302][302];
int a[302][302];
int dy[] = {0,1,0,-1};
int dx[] = {1,0,-1,0};
int main(){
    string s;
    queue<pair<int,int>> q;
    queue<pair<int,int>> qq;
    cin >> N >> M;
    cin >> yy >> xx >> yyy >> xxx;
    for(int i = 0;i < N;i++){
        cin >> s;
        for(int j = 0;j < M;j++){
            if(s[j] == '1'){
                a[i][j] = 1;
            }
            else if(s[j] == '0'){
                a[i][j] = 0;
            }
            else if(s[j] == '*'){
                a[i][j] = 0;
                q.push({i,j});
                visited[i][j] = 1;
            }
            else if(s[j] == '#'){
                a[i][j] = -1;
            }
        }
    }
    for(int cnt = 1;cnt <= 2000;cnt++){
        while(q.size()){
            tie(y,x) = q.front(); q.pop();
            for(int i = 0;i < 4;i++){
                int ny = y + dy[i];
                int nx = x + dx[i];
                if(ny < 0 || ny >= N || nx < 0 || nx >= M || visited[ny][nx]) continue;
                if(a[ny][nx] == 0){
                    q.push({ny, nx});
                    visited[ny][nx] = visited[y][x];
                }
                else if(a[ny][nx] == 1){
                    qq.push({ny, nx});
                    visited[ny][nx] = visited[y][x] + 1;
                }
                else if(a[ny][nx] == -1){
                    cout << visited[y][x];
                    return 0;
                }
            }
        }
        while(qq.size()){
            q.push(qq.front()); 
            qq.pop();
        }
    }

    return 0;
}
