#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int main(){
    int n, k, dp[10002];
    vector<int> v;
    dp[0] = 0;
    cin >> n >> k;
    for(int i = 1;i <= k;i++){
        dp[i] = 1e9;
    }
    for(int i = 0;i < n;i++){
        int inp;
        cin >> inp;
        if(inp <= k){
            v.push_back(inp);
            dp[inp] = 1;
        }
    }
    for(int i = 1;i <= k;i++){
        if(dp[i] != 1e9) continue;
        for(int j : v){
            if(i-j >= 0 && dp[i-j]+1 < dp[i]){
                dp[i] = dp[i-j]+1;
            }
        }
    }
    if(dp[k] == 1e9) cout << -1;
    else cout << dp[k];

    return 0;
}
