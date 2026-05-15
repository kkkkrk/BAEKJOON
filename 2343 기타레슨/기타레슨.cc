#include <iostream>
#include <vector>
using namespace std;
int n, m, l, r, biggest, ret, sum, chk, mid;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    vector<int> v(n);
    for(int i = 0;i < n;i++){
        cin >> v[i];
        biggest = max(biggest,v[i]);
    }
    r = biggest * n;
    while(l <= r){
        mid = (l+r) / 2;
        if(mid < biggest){
            l = mid + 1;
            continue;
        }
        chk = 1;
        sum = 0;
        for(int i = 0;i < n;i++){
            if(sum + v[i] > mid){
                chk++;
                sum = 0;
            }
            sum += v[i];
        }
        if(chk > m){
            l = mid + 1;
        }
        else{
            r = mid - 1;
            ret = mid;
        }
    }
    cout << ret;
    return 0;
}
