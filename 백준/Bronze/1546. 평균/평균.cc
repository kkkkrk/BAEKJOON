#include <iostream>
using namespace std;
int main() {
    int N;
    double biggest = 0.0;
    double sum = 0.0;
    cin >> N;
    for(int i = 0;i < N;i++){
        double a;
        cin >> a;
        if(biggest < a) biggest = a;
        sum += a;
    }
    sum = (sum / biggest) *100.0;
    cout << sum / N;
    return 0;
}