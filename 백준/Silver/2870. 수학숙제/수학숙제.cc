#include <bits/stdc++.h>
using namespace std;
vector<string> v;
bool cmp(string a, string b){
    if(a.length() == b.length()) return a < b;
    return a.length() < b.length();
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int N;
    string s, c;
    cin >> N;
    for(int i = 0;i < N;i++){
        c.clear();
        cin >> s;
        for(int i =0;i < s.length();i++){
            if(s[i] == '0' && c.length() == 0 && s.length() -1 != i && isdigit(s[i+1])){
                continue;
            }
            if(isdigit(s[i]) ) {
                if(s.length() -1 == i || !isdigit(s[i+1])){
                    c += s[i];
                    v.push_back(c);
                    c.clear();
                }
                else{
                    c += s[i];
                }
            }
        }
        // cout << "c: " << c << "\n";
    }
    sort(v.begin(), v.end(), cmp);
    for(string i: v){
        cout << i << "\n";
    }
    
    
    return 0;
}