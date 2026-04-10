#include <bits/stdc++.h>
using namespace std;
int a[1000002], ret[1000002], N;
stack<int> s;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    memset(ret, -1, sizeof(ret));
    for(int i = 0;i < N;i++){
        cin >> a[i];
        while(s.size() && a[s.top()] < a[i]){
            ret[s.top()] = a[i]; s.pop();
        }
        s.push(i);
    }
    for(int i = 0;i < N;i++){
        cout << ret[i] << " ";
    }
    return 0;
}