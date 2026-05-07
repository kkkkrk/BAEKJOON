#include <bits/stdc++.h>
using namespace std;
int r,c,t,ret,flag,f1,f2;
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
int a[51][51], aa[51][51];
int main(){
    cin >> r >> c >> t;
    flag = 1;
    for(int i = 0;i < r;i++){
        for(int j = 0;j < c;j++){
            cin >> a[i][j];
            if(a[i][j] == -1){
                if(flag) {
                    f1 = i;
                    flag = 0;
                }
                else f2 = i;
            }
        }
    }
    for(int time = 0;time < t;time++){
        for(int i = 0;i < r;i++){
            for(int j = 0;j < c;j++){
                int th = a[i][j] / 5;
                if(!th) continue;
                for(int k = 0;k < 4;k++){
                    int ny = i + dy[k];
                    int nx = j + dx[k];
                    if(ny < 0 || ny >= r || nx < 0 || nx >= c || a[ny][nx] == -1) continue;
                    aa[ny][nx] += th;
                    a[i][j] -= th;
                }
            }
        }
        for(int i = 0;i < r;i++){
            for(int j = 0;j < c;j++){
                a[i][j] += aa[i][j];
            }
        }
        memset(aa,0,sizeof(aa));
        
        for(int i = f1-1;i > 0;i--){
            a[i][0] = a[i-1][0];
        }
        for(int i = 0;i < c-1;i++){
            a[0][i] = a[0][i+1];
        }
        for(int i = 0;i < f1;i++){
            a[i][c-1] = a[i+1][c-1];
        }
        for(int i = c-1;i > 1;i--){
            a[f1][i] = a[f1][i-1];
        }
        a[f1][1] = 0;
        
        for(int i = f2 + 1;i < r-1;i++){
            a[i][0] = a[i+1][0];
        }
        for(int i = 0;i < c-1;i++){
            a[r-1][i] = a[r-1][i+1];
        }
        for(int i = r-1;i > f2;i--){
            a[i][c-1] = a[i-1][c-1];
        }
        for(int i = c-1;i > 1;i--){
            a[f2][i] = a[f2][i-1];
        }
        a[f2][1] = 0;
    }
    ret = 2;
    for(int i = 0;i < r;i++){
        for(int j = 0;j < c;j++){
            ret += a[i][j];
        }
    }
    cout << ret;
    return 0;
}
