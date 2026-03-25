#include <bits/stdc++.h>
using namespace std;
bool VPS(const string &inp){
    stack<char> st;
    st.push(inp[0]);
    for(int i = 1;i < inp.size();i++){
        if(st.size() && inp[i] == ')'){
            if(st.top() == '('){
                st.pop();
            }
        }
        else{
            st.push(inp[i]);
        }
    }
    if(st.size()) return 0;
    return 1;
}
int main(){
    int T;
    cin >> T;
    for(int i =0;i < T;i++){
        string s;
        cin >> s;
        if(VPS(s)) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
    
    return 0;
}