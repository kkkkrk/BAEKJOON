#include <bits/stdc++.h>
using namespace std;
const int MAX = 200000;
int N, K;
int visited[200004];

int main(){
    cin >> N >> K;
    queue<int> q;
    q.push(N);
    visited[N] = 1;
    while(q.size()){
        int now = q.front(); q.pop();
        for(int next : {now+1, now-1, now*2}){
            if(next >= 0 && next <= MAX){
                if(!visited[next]){
                    visited[next] = visited[now] + 1;
                    q.push(next);
                }
            }
        }
    }
    cout << visited[K] - 1;
    return 0;
}
