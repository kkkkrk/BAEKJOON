#include <bits/stdc++.h>
using namespace std;
bool VPS(const string &inp){
    stack<char> st;
    for(int i = 0;i < inp.size();i++){
        if(st.size() && inp[i] == ')' && st.top() == '('){
            st.pop();
        }
        else if(st.size() && inp[i] == ']' && st.top() == '['){
            st.pop();
        }
        else if(inp[i] == ')' || inp[i] == '(' || inp[i] == ']' || inp[i] == '['){
            st.push(inp[i]);
        }
    }
    if(st.size()) return 0;
    return 1;
}
int main(){
    while(1){
        string s;
        getline(cin, s);
        if(s == ".") break;
        if(VPS(s)) cout << "yes" << "\n";
        else cout << "no" << "\n";
    }
    
    return 0;
}