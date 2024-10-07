#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <typeinfo>
using namespace std;
int main()
{
    int N;
    cin >> N;
    vector<int> v;
    string str = to_string(N);
    
    for(int i = 0;i < str.size();i++){
        // char a = str[i];
        v.push_back(str[i] - 48);    
    }
    sort(v.begin(), v.end(), greater<int>());
    for(int i = 0;i < v.size();i++){
        cout << v[i];
    }
    

    return 0;
}