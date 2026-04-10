#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int big = -100;
    int index = -1;
    for(int i = 1;i < 10;i++){
        int b;
        cin >> b;
        if(b > big){
            big = b;
            index = i;
        }
    }
    cout << big << endl << index;
    return 0;
}