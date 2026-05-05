#include <bits/stdc++.h>
using namespace std;
int N, sum, ret, l, f;
bool che[4000001];
vector<int> v;
int main(){
    cin >> N;
    for(int i = 2;i <= N;i++){
        if(che[i]) continue;
        for(int j = 2*i;j <= N;j += i) che[j] = 1;
    }
    for(int i = 2;i <= N;i++){
        if(!che[i]) v.push_back(i);
    }
    
    while(1){
        if(sum <= N){
            if(v.size() == l) break;
            sum += v[l++];
        }
        else {
            if(v.size() == f) break;
            sum -= v[f++];
        }
        if(sum == N)ret++;
    }
    cout << ret;
    return 0;
}
