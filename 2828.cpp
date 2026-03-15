#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, M, J;
    cin >> N >> M;
    cin >> J;
    int L = 0;
    int R = M;
    int result = 0;
    for(int i = 0;i < J;i++){
        int a;
        cin >> a;
        if(a > R){
            result += (a - R);
            L += (a - R);
            R += (a - R);
        }
        else if( a <= L){
            result += (L - a + 1);
            R -= (L - a + 1);
            L -= (L - a + 1);
            
        }
    }
    cout << result;
    
    return 0;
}