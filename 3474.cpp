#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T, N, result; 
    cin >> T;
    for(int i = 0;i < T;i++){
        cin >> N;
        result = 0;
        while(N >= 5){
            result += N/5;
            N = N/5;
        }
        cout << result << "\n";
    }
    
    return 0;
}