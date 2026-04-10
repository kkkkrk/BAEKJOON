#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main()
{
    double x_A, y_A, x_B, y_B, x_C, y_C;
    int flag = 0;
    
    cin >> x_A >> y_A >> x_B >> y_B >> x_C >> y_C;
    if((x_A - x_B)/(y_A - y_B) == (x_A - x_C)/(y_A - y_C)) flag = 1;
    if((y_A - y_B)/(x_A - y_B) == (y_A - y_C)/(x_A - x_C)) flag = 1;
    double a1 = sqrt((x_A - x_B)*(x_A - x_B) + (y_A - y_B)*(y_A - y_B));
    double a2 = sqrt((x_C - x_B)*(x_C - x_B) + (y_C - y_B)*(y_C - y_B));
    double a3 = sqrt((x_A - x_C)*(x_A - x_C) + (y_A - y_C)*(y_A - y_C));
    
    double b1 = 2.0*(a1 + a2);
    double b2 = 2.0*(a3 + a2);
    double b3 = 2.0*(a1 + a3);
    
    double biggest = b1;
    if(biggest < b2) biggest = b2;
    if(biggest < b3) biggest = b3;
    
    double smallest = b1;
    if(smallest > b2) smallest = b2;
    if(smallest > b3) smallest = b3;
    
    cout.precision(16);
    if(flag) cout << double(-1.0);
    else cout << double(biggest - smallest);
    return 0;
}