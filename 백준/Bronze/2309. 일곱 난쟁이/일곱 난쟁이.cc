#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v;
    vector<int> result;
    int sum = 0;
    for(int i =0;i <9;i++){
        int a;
        cin >> a;
        sum += a;
        v.push_back(a);
    }
    bool flag = false;
    for(int i =0;i <9;i++){
        for(int j = 0;j < 9;j++){
            if(i == j) continue;
            if(sum - v[i] -v[j] == 100){
                for(int k = 0;k < 9;k++){
                    if(k == i || k == j) continue;
                    result.push_back(v[k]);
                }
                flag = true;
                break;
            }
        }
        if(flag) break;
    }
    sort(result.begin(), result.end());
    for(int i: result){
        cout << i << "\n";
    }
    return 0;
}
