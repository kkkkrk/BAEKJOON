#include <bits/stdc++.h>
using namespace std;
int time_h[104];
int main()
{
    int A,B, C;
    cin >> A >> B >> C;
    int num = 0;
    for(int i = 0;i < 3;i++){
        int a,b;
        cin >> a >> b;
        for(int j = a;j < b;j++){
            time_h[j] += 1;
        }
    }
    for(int i = 0;i < 104;i++){
        if(time_h[i] == 1) num += A;
        else if(time_h[i] == 2) num += (B*2);
        else if(time_h[i] == 3) num += (C*3);
    }
    cout << num;
    
    return 0;
}