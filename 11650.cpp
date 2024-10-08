#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(pair<int,int>&x, pair<int, int>&y){
    if(x.first == y.first) return x.second < y.second;
    return x.first < y.first;
}
int main()
{
    vector<pair<int,int>> v;
    int N;
    cin >> N;
    for(int i = 0;i < N;i++){
        int a,b;
        cin >> a >> b;
        v.push_back(make_pair(a,b));
    }
    sort(v.begin(), v.end(), cmp);
    for(auto n: v){
        cout << n.first << " " << n.second << "\n";
    }
    

    return 0;
}