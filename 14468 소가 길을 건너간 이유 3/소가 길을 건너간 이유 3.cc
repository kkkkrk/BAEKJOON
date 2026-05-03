#include <bits/stdc++.h>
using namespace std;
int a,b,ret, N;
vector<pair<int,int>> v;
int main(){
    cin >> N;
    for(int i = 0;i < N;i++){
        cin >> a >> b;
        v.push_back({a,b});
    }
    sort(v.begin(), v.end());
    // for(auto it : v) cout << it.first << ' ' << it.second << "\n";
    for(auto it : v){
        ret = max(it.first, ret);
        ret += it.second;
    }
    cout << ret;
    return 0;
}
