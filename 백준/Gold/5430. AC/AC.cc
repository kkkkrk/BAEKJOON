#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    char c;
    cin >> T;
    for(int i = 0;i < T;i++){
        string s,ss;
        int n,nn, num, top = 0, flag = 1;
        bool chk = 1;
        bool isError = false;
        vector<int> v;
        cin >> s; cin >> nn; cin >> ss;
        n = nn -1;
        string temp = "";
        for(int j = 0;j < ss.length();j++){
            if(isdigit(ss[j])){
                temp += ss[j];
            }
            else{
                if(!temp.empty()){
                    v.push_back(stoi(temp));
                    temp = "";
                }
            }
        }
        for(auto a : s){
            if(a == 'R') chk = !chk;
            else if(a == 'D'){
                if(top > n) {
                    isError = true;
                    break;
                }
                if(chk)top += 1; 
                else n -= 1;
            }
        }
        if(isError){
            cout << "error\n";
        }
        else{
            cout << '[';
            if(chk){
                for(int j = top;j <= n;j++) cout << v[j] << (j==n ? "":",");
                cout << "]\n";
            }
            else{
                for(int j = n;j >= top;j--) cout << v[j] << (j==top ? "":",");
                cout << "]\n";
            }
        }
    }
    return 0;
}