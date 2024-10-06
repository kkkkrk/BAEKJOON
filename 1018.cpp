#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    int N, M;
    int min = 10000000;
    vector<vector<bool>> v(100);
    cin >> N >> M;
    for(int i = 0;i < N;i++){
        for(int j = 0;j < M;j++){
            char a;
            cin >> a;
            if(a=='W') v[i].push_back(1);
            else v[i].push_back(0);
        }
    }
    for(int i = 0;i < N-7;i++){
        for(int j = 0;j < M-7;j++){
            bool cnt = 1;
            int sum = 0;
            for(int x = i;x < i+8;x++){
                for(int y = j;y < j+8;y++){
                    if(v[x][y] == cnt){
                        sum = sum + 1;
                    }
                    // cout << cnt << v[x][y] << " ";
                    cnt = !cnt;
                }
                cnt = !cnt;
            }
            if(sum < min){
                min = sum;
            }
            cnt = 0;
            sum = 0;
            for(int x = i;x < i+8;x++){
                for(int y = j;y < j+8;y++){
                    if(v[x][y] == cnt){
                        sum = sum + 1;
                    }
                    cnt = !cnt;
                }
                cnt = !cnt;
            }
            if(sum < min){
                min = sum;
            }
        }
    }
    cout << min;
    

    return 0;
}