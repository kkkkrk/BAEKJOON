#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
int main()
{
    long long N;
    cin >> N;
    long long result = 1;
    for(int i = 2;i <= N;i++){
        result  = result*i;
    }
    cout << result;

    return 0;
}