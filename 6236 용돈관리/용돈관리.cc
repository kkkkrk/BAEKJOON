#include <iostream>
#include <vector>
using namespace std;
int n,m,l = 1,r, ret,sum,chk,mid;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    vector<int> v(n);
    for(int i = 0;i < n;i++){
        cin >> v[i];
        r = max(r,v[i]);
        sum += v[i];
    }
    r *= n;
    while(l <= r){
        mid = (l + r) / 2;
        sum = mid; chk = 1;
        for(int i = 0; i< n;i++){
            if(sum >= v[i]){
                sum -= v[i];
            }
            else {
                chk++;
                sum = mid - v[i];
            }
        }
        if(chk > m){
            l = mid + 1;
        }
        else{
            ret = mid;
            r = mid - 1;
        }
        // cout << "l: " << l << " r: " << r << " mid: " << mid  << " ret: " << ret <<  '\n';
    }
    cout << ret;
    
    return 0;
}
