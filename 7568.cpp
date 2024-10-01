#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    int N;
    cin >> N;
    vector<int> height;
    vector<int> weight;
    vector<int> result;
    for(int i = 0;i < N;i++){
        int a,b;
        cin >> a >> b;
        height.push_back(a);
        weight.push_back(b);
    }
    
    for(int i = 0;i < N;i++){
        int a = 1;
        for(int j = 0;j < N;j++){
            if(height[j]>height[i] && weight[j]>weight[i]){
                a = a + 1;
            }
        }
        result.push_back(a);
    }
    
    for(int i = 0;i < N;i++){
        cout << result[i] << " ";
    }
    return 0;
}