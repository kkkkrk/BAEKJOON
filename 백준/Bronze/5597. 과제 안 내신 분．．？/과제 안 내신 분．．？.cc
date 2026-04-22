#include <iostream>
using namespace std;
bool student[33];

int main() {
    for(int i = 0;i < 28;i++){
        int a;
        cin >> a;
        student[a] = 1;
    }
    for(int i = 1;i <= 30;i++){
        if(!student[i]) cout << i << "\n";
    }
    
    return 0;
}