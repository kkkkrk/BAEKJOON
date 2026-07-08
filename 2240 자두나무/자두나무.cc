#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int T, W, dp[1002][32][3], jadoo[1004];
int go(int idx, int cnt, int pos){
    if(cnt < 0) return -1e9;
    if(idx >= T) return 0;
    int &ret = dp[idx][cnt][pos];
    if(ret != -1) return ret;
    return ret = max(go(idx+1, cnt, pos), go(idx+1, cnt-1, pos ^ 1)) + (pos+1 == jadoo[idx]);
}
int main(){
    cin >> T >> W;
    for(int i = 0;i < T;i++){
        cin >> jadoo[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << max(go(0, W, 0), go(0, W-1, 1));

    return 0;
}
