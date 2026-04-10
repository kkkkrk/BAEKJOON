#include <iostream>
#include <string>
#include <list>
using namespace std;

int main()
{
    list<char> L;
    string s;
    cin >> s;
    int M;
    cin >> M;
    cin.ignore(); 

    for(int i = 0;i < s.length();i++){
        L.push_back(s[i]);
    }
    auto it = L.end();
    for(int i = 0;i < M;i++){
        string a;
        getline(cin, a);
        if(a[0] == 'L') {
            if(it != L.begin()){
                it--;
            }   
        }
        else if(a[0] == 'D') {
            if(it != L.end()){
                it++;
            }
        }
        else if(a[0] =='P'){
            L.insert(it, a.back());    
        }
        else if(a[0] =='B'){
            if(it != L.begin()){
                it--;
                it = L.erase(it);
            }
            
        }
        //a.clear();
    }
    
    for(char ii:L){
        cout << ii;
    }

    return 0;
}