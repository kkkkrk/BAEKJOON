#include <bits/stdc++.h>
using namespace std;
int N, K,a,b;
long long ret;
vector<pair<int,int>> v;
vector<int> bag;
priority_queue<int> pq;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> K;
    for(int i = 0;i < N;i++){
        cin >> a >> b;
        v.push_back({a,b});
    }
    for(int i = 0;i < K;i++){
        cin >> a;
        bag.push_back(a);
    }
    sort(v.begin(), v.end());
    sort(bag.begin(), bag.end());
    int idx = 0;
    for(int i = 0;i < K;i++){
        while(idx < N && v[idx].first <= bag[i]){
            pq.push(v[idx++].second);
        }
        if(pq.size()){
            ret += pq.top();
            pq.pop();
        }
    }
    cout << ret;
    return 0;
}
