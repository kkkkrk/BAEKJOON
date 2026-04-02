#include <bits/stdc++.h>
using namespace std;
int main(){
    int N;
    int ret = 0;
    cin >> N;
    int a,flag;
    for(int i = 0;i < N;i++){
        cin >> a;
        flag = 1;
        for(int j = 2;j*j <= a;j++){
            if(a % j == 0) flag = 0;
        }
        if(a == 1) flag = 0;
        if(flag) ret += 1;
    }
    cout << ret;
    return 0;
}
