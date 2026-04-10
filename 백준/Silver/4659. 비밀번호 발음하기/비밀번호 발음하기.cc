#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    string s;
    bool flag;
    bool a;
    vector<bool> v;
    while(1){
        cin >> s;
        if(s == "end") break;
        v.clear();
        flag = 1;
        a = 0;
        for(char c: s){
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                a = 1;
                v.push_back(1);
            }
            else {
                v.push_back(0);
            }
        }
        if(!a) flag = 0;
        if(s.length() >= 2 && s[0] == s[1] && s[0] != 'o' && s[0] != 'e') flag = 0;
        for(int i = 2;i < s.length() && flag;i++) {
            if(s[i] == s[i-1] && s[i] != 'o' && s[i] != 'e') flag = 0;
            if(v[i] == v[i-1] && v[i-1] == v[i-2]) flag = 0;
        }
        if(flag) cout << '<' << s << '>' << " is acceptable." << "\n";
        else cout << '<' << s << '>' << " is not acceptable." << "\n";
    }
    
    return 0;
}