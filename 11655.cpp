#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    getline(cin, s);
    for(char i:s){
        if(i <= 'm' && i>='a') cout << char(i+13);
        else if(i <= 'z' && i>='n') cout << char(i-13);
        else if(i <= 'M' && i>='A') cout << char(i+13);
        else if(i <= 'Z' && i>='N') cout << char(i-13);
        else if(i == ' ') cout << ' ';
        else cout << i;
    }
    return 0;
}