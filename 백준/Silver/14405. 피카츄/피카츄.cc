#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    int l = s.length();
    if(l == 0){
        cout << "NO";
        return 0;
    }
    for(int i = 0;i < l;i++){
        if(s[i] == 'p'){
            if(l - i >= 2){
                if(s[i+1] != 'i'){
                    cout << "NO";
                    return 0;
                } else{
                    i += 1;
                }
            }
            else{
                cout << "NO";
                return 0;
            }
        }
        else if(s[i] == 'k'){
            if(l - i >= 2){
                if(s[i+1] != 'a'){
                    cout << "NO";
                    return 0;
                } else{
                    i += 1;
                }
            }
            else{
                cout << "NO";
                return 0;
            }
        }
        else if(s[i] == 'c'){
            if(l - i >= 3){
                if(s[i+1] != 'h'){
                    cout << "NO";
                    return 0;
                } 
                else if(s[i+2] != 'u'){
                    cout << "NO";
                    return 0;
                }
                else{
                    i += 2;
                }
            }
            else{
                cout << "NO";
                return 0;
            }
        }
        else{
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}