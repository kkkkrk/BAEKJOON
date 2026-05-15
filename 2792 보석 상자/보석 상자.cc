#include <iostream>
#include <vector>
using namespace std;
int n, m, chk, mid, ret,l,r;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    vector<int> v(m);
    for(int i = 0;i < m;i++) {
        cin >> v[i];
        r = max(r, v[i]);
    }
    
    while(l <= r){
        chk = 0;
        mid = (l+r) / 2;
        // cout << "l: " << l << " r: " << r << " mid: " << mid;
        for(int i = 0;i < m;i++){
            chk += (v[i] / mid);
            if(v[i] % mid) chk++;
        }
        // cout << " chk: " << chk;
        if(chk > n) l = mid + 1;
        else{
            ret = mid;
            r = mid -1;
        }
        // cout << " ret: " << ret << '\n';
    }
    cout << ret;

    return 0;
}
