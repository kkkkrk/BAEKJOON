#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    unsigned long long N;
    vector<unsigned long long> dice;
    vector<unsigned long long> min;
    for(unsigned long long i = 0;i < 6;i++){
        min.push_back(0);
    }
    cin >> N;
    for(unsigned long long i = 0;i < 6;i++){
        unsigned long long a;
        cin >> a;
        dice.push_back(a);
    }
    unsigned long long mini = dice[0];
    unsigned long long mini_index = 0;
    unsigned long long biggest = dice[0];
    unsigned long long biggest_index = 0;
    
    for(unsigned long long i = 1;i < 6;i++){
        if(mini > dice[i]){
            mini = dice[i];
            mini_index = i;
        }
        if(biggest < dice[i]){
            biggest = dice[i];
            biggest_index = i;
        }
    }
    min[0] = mini;
    for(unsigned long long i = 0;i < 6;i++){
        if(i != biggest_index){
            min[4] += dice[i];
        }
    }
    unsigned long long a = dice[0] + dice[1];
    for(unsigned long long i = 0;i < 6;i++){
        if(mini_index != i && mini_index + i != 5){
            if(a > dice[i] + mini){
                a = dice[i] + mini;
            }
        }
    }
    min[1] = a;
    min[2] = dice[0] + dice[1] + dice[2];
    for(unsigned long long i = 0;i < 6;i++){
        if(i == mini_index || i + mini_index == 5) continue;
        for(unsigned long long j = i+1;j < 6;j++){
            if(j == mini_index || j + mini_index == 5 || j + i == 5) {
                continue;
            }
            if(min[2] > dice[i] + dice[j] + mini) min[2] = dice[i] + dice[j] + mini;
            
        }
    }
    unsigned long long d1 = 0, d2 = 0, d3 = 0;
    if(N >= 3){
        d1 = (N-2)*(N-1)*4 + (N-2)*(N-2);
    }
    d2 = (N-1)*4 + (N-2)*4;
    if(N > 1) d3 = 4;
    if(N==1) cout << min[4];
    else cout << d1*min[0] + d2*min[1] + d3*min[2];
    
    return 0;
}
