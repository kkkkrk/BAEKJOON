#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
    int N;
    cin >> N;
    vector<int> v;
    v.push_back(0);
    for(int i = 1;i <= N;i++){
        int min = 1000000;
        for(int j = 1; j*j <=i;j++){
            if(v[i-j*j]+1<min){
                min = v[i-j*j] + 1; 
            }
        }
        v.push_back(min);
    }
    cout << v[N];
    return 0;
}