#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int N, M, inp, tmp;
    int result = 0;
    vector<int> v;
    cin >> N;
    cin >> M;
    for(int i = 0;i < N;i++){
        cin >> inp;
        v.push_back(inp);
    }
    while(v.size()){
        tmp = v.back();v.pop_back();
        for(int i:v){
            if(tmp + i == M) result += 1;
        }
    }
    cout << result;
    
    return 0;
}