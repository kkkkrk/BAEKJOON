#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#define X first
#define Y second
using namespace std;
bool board[502][502];
bool vis[502][502];
int n,m;
int answer1 = 0;
int answer2 = 0;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    queue<pair<int,int>> Q;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            bool inp;
            cin >>inp;
            board[i][j] = inp;
        }
    }
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(vis[i][j] == 0 && board[i][j] == 1){
                answer1 += 1;
                int sum = 0;
                Q.push({i,j});
                vis[i][j] = 1;
                while(!Q.empty()){
                    pair<int,int> cur = Q.front();Q.pop();
                    for(int dir = 0;dir < 4;dir++){
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if(nx<0 || nx >= n || ny < 0 || ny >= m) continue;
                        if(vis[nx][ny] == 1|| board[nx][ny] == 0) continue;
                        vis[nx][ny] = 1;
                        sum += 1;
                        Q.push({nx, ny});
                    }
                }
                if(sum + 1> answer2) answer2 = sum + 1;
            }
        }
    }
    cout << answer1 << "\n" << answer2;
    return 0;
}