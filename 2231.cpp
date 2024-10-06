#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
int main()
{
    int N;
    cin >> N;
    int flag = 1;
    if(N > 100) flag = 0;
    int result = 1;
    if(flag){
        for(int i = 1;i<= N;i++){
            int sum = 0;
            int a = i;
            while(a != 0){
                sum += a % 10;
                a /= 10;
            }
            sum += i;
            if(N==sum){
                cout << i;
                result = 0;
                break;
            }
        }
    }
    else{
        for(int i = N-100;i<= N;i++){
            int sum = 0;
            int a = i;
            while(a != 0){
                sum += a % 10;
                a /= 10;
            }
            sum += i;
            if(N==sum){
                cout << i;
                result = 0;
                break;
            }
        }
    }
    if(result) cout << 0;
    return 0;
}