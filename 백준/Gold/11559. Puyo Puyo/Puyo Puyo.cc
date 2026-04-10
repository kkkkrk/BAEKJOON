#include <bits/stdc++.h>
using namespace std;
int y, x, flag;
int dy[] = {0,1,0,-1};
int dx[] = {1,0,-1,0};
int a[13][7];
int gr[7];
bool visited[13][7];

int main(){
    for(int i = 0;i < 12;i++){
        string s;
        cin >> s;
        for(int j = 0;j < 6;j++){
            if(s[j] == 'R') a[i][j] = 1;
            else if(s[j] == 'G') a[i][j] = 2;
            else if(s[j] == 'B') a[i][j] = 3;
            else if(s[j] == 'P') a[i][j] = 4;
            else if(s[j] == 'Y') a[i][j] = 5;
        }
    }
    for(int cnt = 0;cnt < 50;cnt++){
        memset(visited, 0, sizeof(visited));
        fill(gr, gr+6, 12);
        flag = 1;
        for(int i = 0;i < 12;i++){
            for(int j = 0; j < 6;j++){
                if(a[i][j] && !visited[i][j]){
                    queue<pair<int,int>> q;
                    stack<pair<int,int>> s;
                    s.push({i,j});
                    int sum = 1;
                    q.push({i,j});
                    visited[i][j] = 1;
                    while(q.size()){
                        tie(y,x) = q.front(); q.pop();
                        for(int k = 0;k < 4;k++){
                            int ny = y + dy[k];
                            int nx = x + dx[k];
                            if(ny < 0 || ny >= 12 || nx < 0 || nx >= 6 || visited[ny][nx]) continue;
                            if(a[y][x] != a[ny][nx]) continue;
                            sum += 1;
                            visited[ny][nx] = 1;
                            q.push({ny,nx});
                            s.push({ny, nx});
                        }
                    }
                    if(sum >= 4){
                        flag = 0;
                        while(s.size()){
                            tie(y,x) = s.top(); s.pop();
                            a[y][x] = 0;
                        }
                    }
                }
            }
        }
        for(int j = 0;j <= 6; j++){
            for(int i = 11;i >= 0;i--){
                if(a[i][j] > 0){
                    if(i == gr[j] -1){
                        gr[j] -= 1;
                    }
                    else{
                        a[gr[j] - 1][j] = a[i][j];
                        a[i][j] = 0;
                        gr[j] -= 1;
                    }
                }
            }
        }
        if(flag){
            cout << cnt;
            return 0;
        }
    }
    return 0;
}