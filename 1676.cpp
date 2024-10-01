#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    int N;
    cin >> N;
    int result = 0;
    
    for(int i = 1;i <= N;i++){
        if(i % 125 == 0){
            result += 3;
        }
        else if(i % 25 == 0){
            result += 2;
        }
        else if(i % 5 == 0){
            result += 1;
        }
    }
    cout << result;
}