#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int t, n, m,l,r,mid, ret, chk;

int main() {
    cin >> t;
    for(int i = 0;i < t;i++){
        cin >> n >> m;
        ret = 0;
        vector<int> a(n), b(m);
        for(int j = 0;j < n;j++) cin >> a[j];
        for(int j = 0;j < m;j++) cin >> b[j];
        sort(b.begin(), b.end());
        for(int j = 0;j < n;j++){
            l = 0; r = m-1; chk = 0;
            while(l <= r){
                mid = (l+r) / 2;
                if(b[mid] < a[j]){
                    chk = max(mid+1, chk);
                    l = mid + 1;
                }
                else{
                    r = mid - 1;
                }
            }
            ret += chk;
        }
        cout<< ret << '\n';
    }
    return 0;
}
