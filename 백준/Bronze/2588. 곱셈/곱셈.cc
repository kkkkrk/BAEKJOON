#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b;
    cin >> a;
    cin >> b;
    int temp, bb;
    temp = b % 10;
    bb = b / 10;
    cout << a * temp << "\n";
    temp = bb % 10;
    bb = bb / 10;
    cout << a * temp << "\n";
    temp = bb % 10;
    bb = bb / 10;
    cout << a * temp << "\n";
    cout << a * b << "\n";

    return 0;
}