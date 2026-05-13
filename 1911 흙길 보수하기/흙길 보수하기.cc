#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
long long n, l,a,b,f,e,ret;
vector<pair<long long,long long>> v;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> l;
    for(int i = 0;i < n;i++){
        cin >> a >> b;
        v.push_back({a,b});
    }
    sort(v.begin(), v.end());
    v.push_back({2100000000,2100000000});
    f = -2100000000;
    e = -2100000000;
    for(auto [i,j] : v){
        long long k;
        if((e-f) % l == 0) k = 0;
        else k = l - (e-f) % l;
        if(i > e+k){
            ret += ((e-f) / l);
            if((e-f) % l) ret += 1;
            f = i;
            e = j;
        }
        else{
            e = j;
        }
    }
    cout << ret;
    return 0;
}
