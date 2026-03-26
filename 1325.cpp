#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int N, M,a,b, next;
    int max = 0;
    vector<int> output;
    bool visited[10002];
    queue<int> q;
    vector<vector<int>> v(10002);
    cin >> N >> M;
    for(int i = 0;i < M;i++){
        cin >> a >> b;
        v[b].push_back(a);
    }
    for(int i = 1;i <= N;i++){
        int sum = 0;
        for(int j = 1;j <= N;j++){
            visited[j] = 0;
        }
        if(v[i].size()){
            q.push(i);
            visited[i] = 1;
            while(q.size()){
                next = q.front();
                q.pop();
                for(int j : v[next]){
                    if(!visited[j]){
                        sum += 1;
                        visited[j] = 1;
                        q.push(j);
                    }
                }
            }
            if(sum > max){
                output.clear();
                output.push_back(i);
                max = sum;
            } 
            else if(sum == max){
                output.push_back(i);
            }
        }
    }
    sort(output.begin(), output.end());
    for(int i:output){
        cout << i << " ";
    }
    // cout << " max: " << max;
    
    return 0;
}
