#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    vector<bool> v;
    for(int i = 0;i < 43;i++){
        v.push_back(0);
    }
    for(int i = 0;i < 10;i++){
        int a;
        cin >> a;
        v[a%42] = 1;
    }
    int sum = 0;
    for(int i = 0;i < 43;i++){
        if(v[i]) {
            sum += 1;
        }
    }
    cout << sum;
    return 0;
}