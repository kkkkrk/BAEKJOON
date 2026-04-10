#include <bits/stdc++.h>
using namespace std;
int tshirt[6];
int N,T,P,ret;
int main(){
    cin >> N;
    for(int i = 0;i < 6;i++){
        cin >> tshirt[i];
    }
    cin >> T >> P;
    for(int i = 0;i < 6;i++){
        ret += tshirt[i] / T;
        if(tshirt[i] % T) ret += 1;
    }
    cout << ret << "\n";
    cout << N / P << " " << N % P;
    return 0;
}