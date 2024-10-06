#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> v;
    for(int i = 0;i < N;i++){
        int a;
        cin >> a;
        v.push_back(a);
    }
    int result = 0;
    for(int i = 0;i < N;i++){
        for(int j = 0;j < N;j++){
            if(i==j) continue;
            for(int k = 0;k < N;k++){
                if(j==k) continue;
                if(i==k) continue;
                if(v[i] + v[j] +v[k] <= M && v[i] + v[j] +v[k] > result) result = v[i] + v[j] +v[k];
            }
        }
    }
    cout << result;
    return 0;
}