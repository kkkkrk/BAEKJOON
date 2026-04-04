#include <bits/stdc++.h>
using namespace std;
int N, K, p;
int ret = INT_MAX;
int visited[200003];
int ret_cnt = 0;
int main(){
    int flag = 1;
    cin >> N >> K;
    for(int i = 0;i < K*2 + 2;i++){
        visited[i] = INT_MAX;
    }
    queue<int> q;
    q.push(N);
    visited[N] = 1;
    if(N >= K) {
        cout << N - K << "\n" << 1;
    }
    else{ 
        while(q.size()){
            p = q.front(); q.pop();
            int v = visited[p];
            if(p == K){
                if(ret > v){
                    ret = v;
                    ret_cnt = 1;
                }
                else if(ret == v){
                    ret_cnt += 1;
                }
                else{
                    cout << ret-1 << "\n" << ret_cnt;
                    flag = 0;
                    return 0;
                }
            }
            if(p-1 >= 0){
                if(visited[p-1] >= v + 1){
                    visited[p-1] = v + 1;
                    q.push(p-1);
                }
            }
            if(p+1 <= K*2){
                if(visited[p+1] >= v + 1){
                    visited[p+1] = v + 1;
                    q.push(p+1);
                }
            }
            if(p*2 <= K*2){
                if(visited[p*2] >= v + 1){
                    visited[p*2] = v + 1;
                    q.push(p*2);
                }
            }
        }
        cout << ret-1 << "\n" << ret_cnt;
    }
    return 0;
}
