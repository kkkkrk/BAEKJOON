#include <bits/stdc++.h>
using namespace std;
int main(){
    int N, cnt = 0;
    vector<string> v;
    string compare;
    cin >> N;
    cin >> compare;
    for(int i =0;i < compare.size();i++){
        if(compare[i] == '*') cnt = i;
    }
    for(int i = 0;i < N;i++){
        string s;
        cin >> s;
        v.push_back(s);
    }
    // cout << "cnt: " << cnt << endl;
    for(auto it: v){
        int flag = 0;
        for(int i = 0;i < cnt;i++){
            if(it[i] != compare[i]){
                flag = 1;
                // cout << "i: " << i << " it[i]: " << it[i] << " compare: " << compare[i] << " 11"<< endl;
                break;
            }
        }
        if(compare.size() > it.size() + 1) flag = 1;
        if(flag) {
            cout << "NE" << "\n";
            continue;
        }
        int compare_c = compare.size() - 1;
        for(int i = it.size() - 1;compare_c > cnt;i -= 1, compare_c -= 1){
            if(it[i] != compare[compare_c]){
                flag = 1;
                // cout << "i: " << i << " it[i]: " << it[i] << " compare_c: "<< compare_c << " compare: " << compare[compare_c] << " 22"<< endl;
                break;
            }
        }
        if(flag) {
            cout << "NE" << "\n";
        }
        else{
            cout <<"DA" << "\n";
        }
    }
    return 0;
}