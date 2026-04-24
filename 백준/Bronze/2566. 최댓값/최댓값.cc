#include <iostream>
using namespace std;
int main() {
    int ret = -10, ii = 0, jj = 0;
    for(int i =1;i <= 9;i++){
        for(int j = 1;j <= 9;j++){
            int a;
            cin >> a;
            if(a > ret){
                ret = a;
                ii = i;
                jj = j;
            }
        }
    }
cout << ret << '\n' << ii << ' ' << jj;
    return 0;
}