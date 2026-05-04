#include <bits/stdc++.h>
using namespace std;
int N, a,b, ret, chk;
vector<pair<int,int>> v;
int main(){
    cin >> N;
    for(int i = 0;i < N;i++){
        cin >> a >> b;
        v.push_back({b,a});
    }
    sort(v.begin(), v.end());
    for(auto it : v){
        if(chk <= it.second){
            chk = it.first;
            ret += 1;
        }
    }
    cout << ret;
    return 0;
}
