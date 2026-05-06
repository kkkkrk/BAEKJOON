#include <bits/stdc++.h>
using namespace std;
int n, ret, k,a, m[102], mIdx, pri[102], bb,idx;
bool flag;
vector<int> v;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> k;
    for(int i = 0;i < k;i++){
        cin >> a;
        v.push_back(a);
    }
    for(int i = 0;i < k;i++){
        if(mIdx < n){
            flag = 1;
            for(int j = 0;j < mIdx;j++) {
                if(m[j] == v[i]){
                    flag = 0;
                }
            }
            if(flag) {
                m[mIdx++] = v[i];
            }
        }
        else{
            flag = 0;
            for(int j = 0;j < n;j++){
                if(m[j] == v[i]) {
                    flag = 1;
                    break;
                }
            }
            if(flag) continue;
            ret += 1;
            for(int j = 0;j < n;j++){
                flag = 1;
                for(int q = i;q < k;q++){
                    if(v[q] == m[j]) {
                        flag = 0;
                        pri[j] = q;
                        break;
                    }
                }
                if(flag) pri[j] = 10000;
            }
            bb = 0;
            for(int j = 0;j < n;j++){
                if(pri[j] > bb){
                    bb = pri[j];
                    idx = j;
                }
            }
            m[idx] = v[i];
        }
    }
    cout << ret;
    return 0;
}
