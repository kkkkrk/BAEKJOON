#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int M;
    int a = 0;
    cin >> M;
    for(int i = 0;i < M;i++){
        string s;
        cin >> s;
        if(s == "all"){
            a = (1 << 20) -1;
        }
        else if(s == "empty"){
            a = 0;
        }
        else{
            int num;
            cin >> num;
            num -= 1;
            if(s == "add"){
                a |= (1 << num);
            }
            else if(s == "remove"){
                a &= ~(1 << num);
            }
            else if(s == "check"){
                if(a & (1 << num)) cout << 1 << "\n";
                else cout << 0 << "\n";
            }
            else if(s == "toggle"){
                a ^= (1 << num);
            }
        }
    }

    return 0;
}