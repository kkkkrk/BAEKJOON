#include <bits/stdc++.h>
using namespace std;
const int MAX = 200000;
int N, K;
int visited[200004];
stack<int> ret;
int min_ret;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
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
    ret.push(K);
    while(1){
        int now = ret.top();
        if(now == N) break;
        if(now - 1 >= 0 && visited[now-1] == visited[now] - 1){
            ret.push(now -1);
        }
        else if(now + 1 <= MAX && visited[now+1] == visited[now] - 1){
            ret.push(now+1);
        }
        else if(now %2 == 0 && visited[now/2] == visited[now] - 1){
            ret.push(now/2);
        }
    }
    cout << visited[K] - 1 << "\n";
    while(ret.size()){
        cout << ret.top() << " ";
        ret.pop();
    }
    return 0;
}
