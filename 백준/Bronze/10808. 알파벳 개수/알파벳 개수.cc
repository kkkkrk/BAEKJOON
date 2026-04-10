#include <bits/stdc++.h>
using namespace std;

int main(){
    string inp;
    vector<int> result;
    for(int i = 0;i < 26;i++){
        result.push_back(0);
    }
    cin >> inp;
    for(const char &s : inp){
        int a = s - 'a';
        result[a] += 1;
    }
    for(int i = 0;i < 26;i++){
        cout << result[i] << " ";
    }
    return 0;
}
