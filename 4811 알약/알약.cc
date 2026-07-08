#include <iostream>
#include <cstring>
using namespace std;
long long tc[32], dp[32][32]; // full half
long long go(int full, int half){
    if(full == 0) return 1;
    if(half < 0) return 0;
    long long & ret = dp[full][half];
    if(ret != -1) return ret;
    return ret = go(full-1, half+1) + go(full, half-1);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(tc, -1, sizeof(tc));
    memset(dp, -1, sizeof(dp));
    
    for(int i = 0;i < 1000;i++){
        int inp;
        cin >> inp;
        if(inp == 0) break;
        if(tc[inp] == -1) tc[inp] = go(inp-1, 1);
        cout << tc[inp] << '\n';
    }

    return 0;
}
