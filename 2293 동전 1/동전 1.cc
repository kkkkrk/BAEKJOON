#include <iostream>
using namespace std;
int n, k, dp[10003];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    dp[0] = 1;
    for(int i = 0;i < n;i++){
        int inp;
        cin >> inp;
        if(inp > k) continue;
        for(int j = inp;j <= k;j++){
            dp[j] += dp[j-inp];
        }
    }
    cout << dp[k];

    return 0;
}
