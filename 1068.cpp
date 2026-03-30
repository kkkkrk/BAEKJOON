#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, a, delt;
    queue<int> q;
    int result = 0;
    vector<vector<int>> v(52);
    cin >> N;
    for(int i = 0;i < N;i++){
        cin >> a;
        if(a == -1){
            q.push(i);
        }
        else{
            v[a].push_back(i);
        }
    }
    cin >> delt;
    if(q.front() != delt){
        while(q.size()){
            int nextt = q.front(); q.pop();
            if(!v[nextt].size()) result += 1;
            else if(v[nextt].size() == 1 && v[nextt][0] == delt) {
                result += 1;
            }
            for(int nt:v[nextt]){
                if(nt != delt){
                    q.push(nt);
                }
            }
        }
    }
    cout << result;
    return 0;
}
