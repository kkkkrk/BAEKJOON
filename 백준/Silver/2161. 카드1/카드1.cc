#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int start[1010], N;
    vector<int> answer;
    cin >> N;
    for(int i = 0;i <N;i++){
        start[i] = N - i;
    }
    
    for(int i = N -1;i >0;i--){
        answer.push_back(start[i]);
        int tmp = start[i - 1];
        for(int j = i-1;j > 0;j--){
            start[j] = start[j-1];
        }
        start[0] = tmp;
    }
    answer.push_back(start[0]);
    
    for(int i = 0;i < N;i++){
        cout << answer[i] << " ";
    }
    
    return 0;
}