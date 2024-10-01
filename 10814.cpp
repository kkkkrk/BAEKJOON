#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    int N;
    cin >> N;
    vector<vector<string>> age(202);
    for(int i = 0;i < N;i++){
        int a;
        string str;
        cin >> a >> str;
        age[a].push_back(str);
    }
    for(int i = 1;i <= 200; i++){
        for(int j = 0;j < age[i].size();j++){
            cout << i << " "<< age[i][j] << endl;
        }
    }
    
    

    return 0;
}