#include <bits/stdc++.h>
using namespace std;
int dmg[6][3] = {{9,3,1}, {9,1,3}, {3,9,1}, {3,1,9}, {1,9,3}, {1,3, 9}};
int inp[3];
int visited[61][61][61];
int N;
struct State{
    int a,b,c;
};

int main(){
    cin >> N;
    for(int i = 0;i < N;i++){
        cin >> inp[i];
    }
    queue<State> q;
    q.push({inp[0], inp[1], inp[2]});
    visited[inp[0]][inp[1]][inp[2]] = 1;
    while(q.size()){
        State s = q.front(); q.pop();
        for(int i = 0;i < 6;i++){
            int na = max(0, s.a - dmg[i][0]);
            int nb = max(0, s.b - dmg[i][1]);
            int nc = max(0, s.c - dmg[i][2]);
            if(visited[na][nb][nc]) continue;
            if(na <= 0 && nb <= 0 && nc <= 0){
                cout << visited[s.a][s.b][s.c];
                return 0;
            }
            q.push({na,nb,nc});
            visited[na][nb][nc] = visited[s.a][s.b][s.c] + 1;
        }
    }
    
    return 0;
}