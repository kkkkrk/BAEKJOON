#include <bits/stdc++.h>
using namespace std;
int N, L, R, y, x, cnt, sum, a[52][52];
bool visited[52][52];
int dy[] = {0,1,0,-1};
int dx[] = {1,0,-1,0};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> L >> R;
    for(int i = 0;i < N;i++){
        for(int j = 0;j < N;j++){
            cin >> a[i][j];
        }
    }
    bool flag = 1;
    while(flag){
        flag = 0;
        memset(visited, 0, sizeof(visited));
        for(int i = 0;i < N;i++){
            for(int j = 0;j < N;j++){
                if(visited[i][j] == 0){
                    queue<pair<int, int>> q;
                    vector<pair<int,int>> v;
                    visited[i][j] = 1;
                    sum = a[i][j];
                    v.push_back({i,j});
                    q.push({i,j});
                    while(q.size()){
                        tie(y,x) = q.front(); q.pop();
                        for(int k = 0;k < 4;k++){
                            int ny = y + dy[k];
                            int nx = x + dx[k];
                            if(ny < 0 || ny >= N || nx < 0 || nx >= N || visited[ny][nx]) continue;
                            int cmp = abs(a[y][x] - a[ny][nx]);
                            if(cmp < L || cmp > R) continue;
                            sum += a[ny][nx];
                            v.push_back({ny,nx});
                            q.push({ny,nx});
                            visited[ny][nx] = 1;
                            flag = 1;
                        }
                    }
                    sum /= v.size();
                    for(auto it: v){
                        a[it.first][it.second] = sum;
                    }
                }
            }
        }
        if(flag) cnt += 1;
    }
    cout << cnt;
    return 0;
}