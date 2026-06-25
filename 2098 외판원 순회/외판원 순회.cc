#include <iostream>
using namespace std;
int n, dp[18][1000000], cost[18][18], maxPast = 1;
int go(int now, int past, int nowCost){
    if(past == maxPast) return nowCost + cost[now][0];
    int &ret = dp[now][past];
    if(ret != 30000000) return ret;
    int cmp = 30000000;
    for(int i = 0;i < n;i++){
        if(i == now) continue;
        if(!(past & (1 << i))){
            int a = past | (1 << i);
            dp[i][a] = go(i, a, nowCost + cost[now][i]);
            cmp = min(cmp, dp[i][a]);
        }
    }
    return ret = cmp;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            cin >> cost[i][j];
            if(cost[i][j] == 0) cost[i][j] = 30000000;
        }
    }
    for(int i = 0;i < 18;i++){
        for(int j = 0;j < 1000000;j++){
            dp[i][j] = 30000000; //3e7
        }
    }
    for(int i = 0;i < n;i++){
        maxPast *= 2;
    }
    maxPast -= 1;
    cout << go(0,1,0);
    return 0;
}
