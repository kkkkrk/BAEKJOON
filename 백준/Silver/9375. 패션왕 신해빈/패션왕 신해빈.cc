#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t, n;
    string s1, s2;
    map<string, int> mp;
    cin >> t;
    
    for(int i = 0;i < t;i++){
        cin >> n;
        for(int j = 0;j < n;j++){
            cin >> s1 >> s2;
            mp[s2] += 1;
        }
        int output = 1;
        for(auto it: mp){
            output *= (it.second + 1);
        }
        cout << output - 1 << "\n";
        mp.clear();
    }
    
    return 0;
}