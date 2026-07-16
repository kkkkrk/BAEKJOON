#include <iostream>
using namespace std;
int dp[100001],n,k;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    while(n--){
        int w,v;
        cin >> w >> v;
        for(int i = k;i >= w;i--){
            dp[i] = max(dp[i], dp[i-w]+v);
        }
    }
    cout << dp[k];
    return 0;
}
