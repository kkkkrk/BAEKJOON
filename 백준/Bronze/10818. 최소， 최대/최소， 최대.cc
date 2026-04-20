 #include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    int ret1 = INT_MAX;
    int ret2 = -INT_MAX;
    // cout << ret2 << '\n';
    cin >> N;
    for(int i = 0;i < N;i++){
        int a;
        cin >> a;
        ret1 = min(ret1, a);
        ret2 = max(ret2, a);
    }
    cout << ret1 << ' ' << ret2;
    return 0;
}