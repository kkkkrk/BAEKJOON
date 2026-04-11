#include <bits/stdc++.h>
using namespace std;
bool chki[101][101];
bool chkj[101][101];
bool flag;

int main(){
    int N, L, a[101][101];
    int ret = 0;
    cin >> N >> L;
    for(int i = 0;i < N;i++){
        for(int j = 0;j < N;j++){
            cin >> a[i][j];
        }
    }
    for(int i = 0;i < N;i++){
        flag = 1;
        for(int j = 1;j < N;j++){
            if(a[i][j-1] < a[i][j]){
                if(a[i][j-1] + 1 < a[i][j]){
                    flag = 0;
                    break;
                }
                for(int k = 1;k <= L;k++){
                    if(j-k < 0){
                        flag = 0;
                        break;
                    }
                    else if(a[i][j-k] != a[i][j-1] || chkj[i][j-k]){
                        flag = 0;
                        break;
                    }
                    else{
                        chkj[i][j-k] = 1;
                    }
                }
            }
            else if(a[i][j-1] > a[i][j]){
                if(a[i][j-1] - 1 > a[i][j]){
                    flag = 0;
                    break;
                }
                for(int k = 0;k < L;k++){
                    if(j+k >= N){
                        flag = 0;
                        break;
                    }
                    else if(a[i][j+k] != a[i][j] || chkj[i][j+k]){
                        flag = 0;
                        break;
                    }
                    else{
                        chkj[i][j+k] = 1;
                    }
                }
            }
        }
        if(flag) {
            ret += 1;
        }
    }
    for(int j = 0;j < N;j++){
        flag = 1;
        for(int i = 1;i < N;i++){
            if(a[i-1][j] < a[i][j]){
                if(a[i-1][j] + 1 < a[i][j]){
                    flag = 0;
                    break;
                }
                for(int k = 1;k <= L;k++){
                    if(i-k < 0){
                        flag = 0;
                        break;
                    }
                    else if(a[i-k][j] != a[i-1][j] || chki[i-k][j]){
                        flag = 0;
                        break;
                    }
                    else{
                        chki[i-k][j] = 1;
                    }
                }
            }
            else if(a[i-1][j] > a[i][j]){
                if(a[i-1][j] - 1 > a[i][j]){
                    flag = 0;
                    break;
                }
                for(int k = 0;k < L;k++){
                    if(i+k >= N){
                        flag = 0;
                        break;
                    }
                    else if(a[i+k][j] != a[i][j] || chki[i+k][j]){
                        flag = 0;
                        break;
                    }
                    else{
                        chki[i+k][j] = 1;
                    }
                }
            }
        }
        if(flag) {
            ret += 1;
        }
    }
    cout << ret;
    return 0;
}