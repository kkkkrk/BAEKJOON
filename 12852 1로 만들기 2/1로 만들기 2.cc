#include <iostream>
using namespace std;

int main(){
    int dp[110][2], N;
    cin >> N;
    dp[1][0] = 0;
    
    dp[2][0] = 1;
    dp[2][1] = 1;
    
    dp[3][0] = 1;
    dp[3][1] = 1;
    
    for(int i = 4;i <= N;i++){
        dp[i][0] = dp[i-1][0]+1;
        dp[i][1] = i-1;
        if(i % 3 == 0 && dp[i][0] > dp[i/3][0]+1){
            dp[i][0] = dp[i/3][0]+1;
            dp[i][1] = i/3;
        }
        if(i % 2 == 0 && dp[i][0] > dp[i/2][0]+1){
            dp[i][0] = dp[i/2][0]+1;
            dp[i][1] = i/2;
        }
    }
    cout << dp[N][0] << '\n';
    int i = N;
    cout << N << ' ';
    while(i != 1){
        cout << dp[i][1] << ' ';
        i = dp[i][1];
    }

    return 0;
}
