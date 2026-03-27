#include <bits/stdc++.h>
using namespace std;
int N, M, y, x;
int school[602][602];
bool visited[602][602];
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    queue<pair<int, int>> q;
    cin >> N >> M;
    for(int i = 0;i< N;i++){
        string s;
        cin >> s;
        for(int j = 0;j < M;j++){
            if(s[j] == 'O') school[i][j] = 0;
            else if(s[j] == 'X') school[i][j] = 1;
                else if(s[j] == 'P') school[i][j] = 2;
            else if(s[j] == 'I') {
                school[i][j] = 0;
                q.push({i, j});
                visited[i][j] = 1;
            }
        }
    }
    int result = 0;
    while(q.size()){
        tie(y,x) = q.front(); q.pop();
        for(int i = 0;i < 4;i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >= N || nx < 0 || nx >= M || school[ny][nx] == 1) continue;
            if(visited[ny][nx]) continue;
            if(school[ny][nx] == 2) result += 1;
            q.push({ny, nx});
            visited[ny][nx] = 1;
        }
    }
    if(result) cout << result;
    else cout << "TT";
    return 0;
}
