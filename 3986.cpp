#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int N;
    string s;
    cin >> N;
    int result = 0;
    for(int i = 0;i < N;i++){
        stack<char> stk;
        cin >> s;
        stk.push(s[0]);
        cout << s << "\n";
        for(int j = 1;j < s.size();j++){
            if(stk.top() == s[j]){
                stk.pop();
            }
            else{
                stk.push(s[j]);
            }
        }
        
        if(stk.empty()) result += 1;
    }
    cout << result;
    return 0;
}