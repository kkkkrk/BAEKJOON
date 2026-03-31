#include <bits/stdc++.h>
using namespace std;
int N, M, sum, y, x, dist;
int ret = INT_MAX;
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
int a[52][52], visited[52][52];
int bfs_house[51][51][51][51];
int chk_chicken[15];
vector<pair<int,int>> chicken, house;
deque<pair<int,int>> s;
void findChicken(int idx, int cnt){
    if(cnt > M) return;
    if(idx >= chicken.size()){ // 각각 bfs 해서 최단거리 구해서 다 더한뒤 ret와 비교
        sum = 0;
        for(auto it: house){
            dist = 1000;
            for(auto it_c: s){
                dist = min(dist, bfs_house[it.first][it.second][it_c.first][it_c.second]);
            }
            sum += dist;
        }
        ret = min(ret, sum);
        return;
    }
    findChicken(idx + 1, cnt);
    s.push_back(chicken[idx]);
    findChicken(idx + 1, cnt + 1);
    s.pop_back();
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> N >> M;
    for(int i = 0;i < N;i++){
        for(int j = 0;j <N;j++){
            cin >> a[i][j];
            if(a[i][j] == 2) { 
                chicken.push_back({i,j});
                a[i][j] = 0;
            }
            else if(a[i][j] == 1) house.push_back({i,j});
        }
    }
    sum = 0;
    for(auto it_h: house){
        for(auto it_c: chicken){
            queue<pair<int,int>> q;
            memset(visited, 0, sizeof(visited));
            int distance = 1000;
            q.push({it_h.first, it_h.second});
            visited[it_h.first][it_h.second] = 1;
            int flag = 0;
            while(q.size()){
                tie(y, x) = q.front(); q.pop();
                for(int i = 0;i < 4;i++){
                    int ny = y + dy[i];
                    int nx = x + dx[i];
                    if(ny < 0 || ny >= N || nx < 0 || nx >= N || visited[ny][nx]) continue;
                    q.push({ny, nx});
                    visited[ny][nx] = visited[y][x] + 1;
                    if(ny == it_c.first && nx == it_c.second) {
                        bfs_house[it_h.first][it_h.second][it_c.first][it_c.second] = visited[ny][nx] - 1;
                        flag = 1;
                        break;
                    }
                }
                if(flag) break;
            }
        }
    }
    findChicken(0, 0);
    cout << ret;
    return 0;
}
