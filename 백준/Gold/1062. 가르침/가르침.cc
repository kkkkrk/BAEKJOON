#include <bits/stdc++.h>
using namespace std;
int N, K, word[51];
int count(int mask){
    int cnt = 0;
    for(int w: word) {
        if(w && (w & mask) == w) cnt++;
    }
    return cnt;
}
int go(int idx, int m, int mask){
    if(m < 0) return 0;
    if(idx >= 26) return count(mask);
    int ret = go(idx + 1, m-1, mask | (1 << idx));
    if(idx != 'a' - 'a' && idx != 'n' - 'a' && idx != 't' - 'a' && idx != 'i' - 'a' && idx != 'c' - 'a'){
        ret = max(ret, go(idx+1, m, mask));
    }
    return ret;
}
int main(){
    cin >> N >> K;
    for(int i = 0;i < N;i++){
        string s;
        cin >> s;
        for(char c : s){
            word[i] |= (1 << c - 'a');
        }
    }
    cout << go(0, K, 0);
    return 0;
}