#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    int N;
    cin >> N;
    vector<int> sixsixsix;
    for(int i = 0;i < 10000000;i++){
        string str = to_string(i);
        if(str.find("666") != string::npos){
            sixsixsix.push_back(i);
        }
    }
    cout << sixsixsix[N-1];

    return 0;
}