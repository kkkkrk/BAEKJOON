#include <bits/stdc++.h>
using namespace std;
int N, a[21][21], chk[21], ret = INT_MAX;
void go(int start, vector<int> &v){
    if(v.size() == N/2){
        int chk1 = 0, chk2 = 0, k = 0;
        vector<int> v2;
        for(int i = 0;i < N;i++){
            if(k < N && v[k] == i){
                k++;
            }
            else{
                v2.push_back(i);
            }
        }
        for(int i = 0;i < N/2;i++){
            for(int j = i+ 1;j < N/2;j++){
                chk1 += a[v[i]][v[j]];
                chk2 += a[v2[i]][v2[j]];
            }
        }
        ret = min(ret, abs(chk1 - chk2));
        return;
    }
    for(int i = start + 1;i < N;i++){
        v.push_back(i);
        go(i, v);
        v.pop_back();
    }
}
int main(){
    cin >> N;
    for(int i = 0;i < N;i++){
        for(int j = 0;j < N;j++){
            cin >> a[i][j];
        }
    }
    for(int i = 0;i < N;i++){
        for(int j = i+1;j < N;j++){
           a[i][j] += a[j][i];
        }
    }
    vector<int> b;
    go(-1, b);
    cout << ret;
    return 0;
}
