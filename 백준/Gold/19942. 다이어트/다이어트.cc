#include <bits/stdc++.h>
using namespace std;
int N;
int a[17][5];
int cmpA[5], cmpB[4];
vector<int> ret2;
int ret = INT_MAX;

int main(){
    cin >> N;
    cin >> cmpB[0] >> cmpB[1] >> cmpB[2] >> cmpB[3];
    for(int i = 0;i < N;i++){
        cin >> a[i][0] >> a[i][1] >> a[i][2] >> a[i][3] >> a[i][4];
    }
    for(int i =(1 << N) -1;i >= 0;i--){
        memset(cmpA, 0, sizeof(cmpA));
        vector<int> cret2;
        for(int j = 0;j < N;j++){
            if(i & (1 << j)){
                for(int k = 0;k < 5;k++){
                    cmpA[k] += a[j][k]; 
                }
                cret2.push_back(j+1);
            }
        }
        bool flag = 1;
        for(int j = 0;j < N;j++){
            for(int k = 0;k < 4;k++){
                if(cmpA[k] < cmpB[k]) flag = 0;
            }
        }
        if(flag && ret > cmpA[4]) {
            ret = cmpA[4];
            ret2 = cret2;
        }
        else if(flag && ret == cmpA[4]){
            if(cret2 < ret2) ret2 = cret2;
        }
    }
    if(ret == INT_MAX){
        cout << -1;
    }
    else{
        cout << ret << "\n";
        for(int c : ret2) cout << c << " ";
    }
    
    return 0;
}