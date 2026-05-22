#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long S, C,mid;
    long long ret,chk,sum = 0;
    int l = 1, r = 0;
    cin >> S >> C;
    vector<int> v(S);
    for(int i = 0;i < S;i++) {
        cin >> v[i];
        r = max(r,v[i]);
        sum += v[i];
    }
    while(l <= r){
        mid = (l+r)/2;
        chk = 0;
        for(int i : v){
            chk += i / mid;
        }
        if(chk < C){
            r = mid - 1;
        }
        else{
            ret = sum - mid*C;
            l = mid + 1;
        }
    }
    cout << ret;
    return 0;
}
