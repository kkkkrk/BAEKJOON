#include <bits/stdc++.h>
using namespace std;
long long min_n = 9999999999;
long long max_n = 0;
int k;
bool a[10];
bool chk[10];
stack<int> s;
void f(int rad){
    int t = s.top();
    if(rad >= k){
        stack<int> ss = s;
        long long aa = 0;
        long long aten = 1;
        while(ss.size()){
            aa += aten * ss.top(); ss.pop();
            aten *= 10;
        }
        max_n = max(max_n, aa);
        min_n = min(min_n, aa);
        return;
    }
    if(a[rad]){
        for(int i = 0;i < t;i++){
            if(!chk[i]) {
                chk[i] = 1;
                s.push(i);
                f(rad + 1);
                chk[i] = 0;
                s.pop();
            }
        }
    }
    else{
        for(int i = t + 1;i <= 9;i++){
            if(!chk[i]) {
                chk[i] = 1;
                s.push(i);
                f(rad + 1);
                chk[i] = 0;
                s.pop();
            }
        }
    }
}
int main(){
    cin >> k;
    for(int i = 0;i < k;i++){
        char c;
        cin >> c;
        if(c == '>') a[i] = 1;
    }
    chk[0] = 1;
    for(int i = 0;i <=9;i++) {
        s.push(i);
        chk[i] = 1;
        f(0);
        s.pop();
        chk[i] = 0;
    }
    cout << max_n << "\n";
    long long kk = 1;
    for(int i = 0;i < k;i++){
        kk *= 10;
    }
    if(min_n < kk){
        cout << 0 << min_n;
    }
    else{
        cout << min_n;
    }

    return 0;
}
