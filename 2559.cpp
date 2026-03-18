#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    vector<int> v;
    vector<int> vSum;
    vector<int> kSum;
    int N, K;
    cin >> N >> K;
    for(int i = 0;i < N;i++){
        int a;
        cin >> a;
        v.push_back(a);
    }
    vSum.push_back(v[0]);
    for(int i = 1;i < N;i++){
        vSum.push_back((vSum[i-1] + v[i]));
    }
    kSum.push_back(vSum[K-1]);
    for(int i = K;i < N;i++){
        kSum.push_back(vSum[i] - vSum[i-K]);
    }
    int biggest = -100000;
    for(int i: kSum){
        biggest = biggest < i ? i : biggest;
    }
    cout << biggest;
    // for(int i = 0;i < N;i++){
    //     cout << v[i] << " ";
    // }
    // cout << endl;
    // for(int i:vSum){
    //     cout << i << " ";
    // }
    return 0;
}