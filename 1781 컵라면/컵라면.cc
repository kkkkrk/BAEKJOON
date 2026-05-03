#include <bits/stdc++.h>
using namespace std;
int N,a,b,ret;
vector<pair<int,int>> v;
priority_queue<int, vector<int>, greater<int>> pq;
int main(){
    cin >> N;
    for(int i = 0;i < N;i++){
        cin >> a >> b;
        v.push_back({a,b});
    }
    sort(v.begin(), v.end());
    for(auto it : v){
        pq.push(it.second);
        ret += it.second;
        if(pq.size() > it.first) {
            ret -= pq.top(); pq.pop();
        }
    }
    cout << ret;
    return 0;
}
