#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, cmp, ret = 0;
    vector<int> v;
    cin >> N;
    for(int i = 0;i < N;i++){
        int a;
        cin >> a;
        v.push_back(a);
    }
    cin >> cmp;
    for(int i : v){
        if(i == cmp) ret += 1;
    }
    cout << ret;
    return 0;
}