#include <bits/stdc++.h>
using namespace std;
int R, C, z, y, x, j_y, j_x;
int ret = INT_MAX;
int dy[] = {0,1,0,-1};
int dx[] = {1,0,-1,0};
char a[1001][1001];
vector<pair<int,int>> fire;
bool visited_f[1001][1001];
int visited_j[1001][1001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> R >> C;
    queue<tuple<int,int, int>> q;
    
    for(int i = 0;i < R;i++){
        // string s;
        // cin >> 
        for(int j = 0;j < C;j++){
            cin >> a[i][j];
            if(a[i][j] == 'F') {
                q.push({i,j, 0});
                visited_f[i][j] = 1;
            }
            if(a[i][j] == 'J') {
                j_y = i;
                j_x = j;
                visited_j[i][j] = 1;
            }
        }
    }

    q.push({j_y, j_x, 1});

     if(j_y == 0 || j_y == R-1 || j_x == 0 || j_x == C-1) ret = 1;
    while(q.size()){
        auto [y,x,z] = q.front(); q.pop();
        for(int i = 0;i < 4;i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >= R || nx < 0 || nx >= C || a[ny][nx] == '#' || visited_f[ny][nx]) continue;
            if(z) {
                if(visited_j[ny][nx]) continue;
                visited_j[ny][nx] = visited_j[y][x] + 1;
                if(ny == 0 || ny == R-1 || nx == 0 || nx == C-1) ret = min(ret, visited_j[ny][nx]);
            }
            else visited_f[ny][nx] = 1;
            q.push({ny, nx, z});
        }
    }
    if(ret == INT_MAX) cout << "IMPOSSIBLE";
    else cout << ret;
    return 0;
}