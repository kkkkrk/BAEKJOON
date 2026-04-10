#include <bits/stdc++.h>
using namespace std;

int main(){
    long long A, B, C;
    vector<long long> v;
    cin >> A >> B >> C;
    v.push_back(A % C);
    for(int i = 1;i <= ceil(log2(B));i++){
        v.push_back((v[i-1]*v[i-1]) % C);
    }
    long long result = v[floor(log2(B))];
    B -= pow(2, floor(log2(B)));
    while(B > 0){
        int p = floor(log2(B));
        result = (result * v[p]) % C;
        B -= pow(2, p);
    }
    cout << result;
    return 0;
}