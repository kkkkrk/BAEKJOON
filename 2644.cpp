#include <bits/stdc++.h>
using namespace std;
const int max_n = 102;
int visited[max_n];
int n, start, endCh, m, now;
int main(){
    cin >> n;
    cin >> start >> endCh;
    cin >> m;
    vector<vector<int>> v(max_n);
    for(int i = 0;i < m;i++){
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    queue<int> q;
    q.push(start);
    visited[start] = 1;
    while(q.size()){
        now = q.front(); q.pop();
        for(int i:v[now]){
            if(visited[i]) continue;
            visited[i] = visited[now] + 1;
            q.push(i);
        }
    }
    if(visited[endCh]) cout << visited[endCh] - 1;
    else cout << -1;
    return 0;
}