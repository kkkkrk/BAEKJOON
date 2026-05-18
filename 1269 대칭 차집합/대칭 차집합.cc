#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,m, aidx, bidx, g;

int main(){
    cin >> n >> m;
    vector<int> a(n), b(m);
    for(int i = 0;i < n;i++) cin >> a[i];
    for(int i = 0;i < m;i++) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    // for(int i = 0;i < n;i++) cout << a[i] << ' ';
    // cout << '\n';
    // for(int i = 0;i < m;i++) cout << b[i] << ' ';
    // cout << '\n';
    while(aidx < n && bidx < m){
        if(a[aidx] == b[bidx]){
            g++; aidx++; bidx++;
        }
        else if(a[aidx] > b[bidx]){
            bidx++;
        }
        else if(a[aidx] < b[bidx]){
            aidx++;
        }
    }
    cout << n+m - (2*g);

    return 0;
}
