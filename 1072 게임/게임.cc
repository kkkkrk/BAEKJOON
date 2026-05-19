#include <iostream>
using namespace std;
int main(){
    long long X, Y,ret = 0;
    cin >> X >> Y;
    long long Z = Y*100/X;
    bool flag = 1;
    long long l = 1, r = 98765432198765;
    while(l <= r){
        long long mid = (l+r)/2;
        long long chk = (Y + mid)*100 / (X + mid);
        if(chk == Z){
            l = mid + 1;
        }
        else{
            flag = 0;
            ret = mid;
            r = mid - 1;
        }
    }
    if(flag) cout << -1;
    else cout << ret;
    return 0;
}
