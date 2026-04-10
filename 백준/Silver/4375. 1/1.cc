#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n;
    vector<int> v_1;
    vector<int> v_10;
    while(cin >> n){
        v_1.clear();
        v_10.clear();
        v_1.push_back(1 % n);
        v_10.push_back(10 % n);
        if(n == 1) {
            cout << 1 << "\n";
            continue;
        }
        for(int i = 1;i < 100000;i++){
            v_10.push_back((v_10[i-1] * v_10[0])%n);
            v_1.push_back((v_1[i-1]+v_10[i-1])%n);
            if(v_1[i] == 0){
                cout << i+1 << "\n";
                break;
            }
        }
    }
    return 0;
}