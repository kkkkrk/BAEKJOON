#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    int N;
    cin >> N;
    vector<string> v;
    vector<vector<string>> vv(52);

    for(int i = 0;i< N;i++){
        string s;
        cin >> s;
        vv[s.length()].push_back(s);
    }
    //cout << "-------------" << endl;
    for(int i = 1;i < 51;i++){
        sort(vv[i].begin(),vv[i].end());
    }
    for(int i = 1;i < 51;i++){
        for(int j = 0;j < vv[i].size();j++){
            if(j < vv[i].size()-1){
                if(vv[i][j] != vv[i][j+1]){
                    cout << vv[i][j] << endl;    
                }
            }
            else{
                cout << vv[i][j] << endl;
            }
            
        }
    }

    return 0;
}