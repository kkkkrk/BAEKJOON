#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long  M,N;
    int T;
    bool flag;
    cin >> T;
    for(int i = 0;i < T;i++){
        cin >> N;
        vector<long long> v(N);
        for(long long j = 0;j < N;j++) cin >> v[j];
        sort(v.begin(), v.end());
        cin >> M;
        long long num;
        for(long long j = 0;j < M;j++) {
            cin >> num;
            long long l = 0, r = N-1,mid;
            flag = 1;
            while(l <= r){
                mid = (l+r)/2;
                if(v[mid] == num){
                    flag = 0;
                    cout << 1 << '\n';
                    break;
                }
                else if(v[mid] > num){
                    r = mid - 1;
                }
                else {
                    l = mid + 1;
                }
            }
            if(flag) cout << 0 << '\n';
        }
        
    }

    return 0;
}
