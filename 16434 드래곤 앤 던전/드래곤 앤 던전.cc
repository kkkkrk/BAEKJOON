#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
long long n, hatk, ret, rett = LLONG_MAX;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> hatk;
    vector<vector<long long>> v;
    for(int i = 0;i < n;i++){
        long long a,b,c;
        cin >> a >> b >> c;
        v.push_back({a,b,c});
        if(a == 1){
            v[i].push_back(hatk);
        }
        else{
            hatk += b;
        }
    }
    long long l = 1, r = LLONG_MAX;
    while(l <= r){
        long long mid = (l+r)/2;
        ret = mid;
        for(int i = 0;i < n;i++){
            if(v[i][0] == 1){
                long long chk = v[i][2] / v[i][3] - 1;
                if(v[i][2] % v[i][3]) chk++;
                ret -= chk*v[i][1];
                if(ret <= 0){
                    ret = -1;
                    break;
                }
            }
            else{
                ret += v[i][2];
                if(ret > mid) ret = mid;
            }
        }
        if(ret< 1){
            l = mid + 1;
        }
        else{
            rett = mid;
            r = mid - 1;
        }
    }

    cout << rett;
    return 0;
}
