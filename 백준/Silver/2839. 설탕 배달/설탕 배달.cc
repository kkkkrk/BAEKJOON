#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int N, flag = 1;
    cin >> N;

    int five = N / 5;

    for(int i = five;i >=0;i--){
        if((N - i*5) % 3 == 0){
            cout << i+(N-i*5) / 3 << endl;
            flag = 0;
            break;
        }
    }

    if(flag) cout << -1 << endl;

    return 0;
}