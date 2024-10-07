#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    int N,k;
    cin >> N >> k;
    vector<int> v;
    for(int i = 0;i < N;i++){
        int a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    cout << v[N-k];

    return 0;
}