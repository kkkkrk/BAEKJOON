#include <bits/stdc++.h>
using namespace std;
int N, a[11][11];
int dy[] = {0,0,1,0,-1};
int dx[] = {0,1,0,-1,0};
int ret = INT_MAX;
int cmpR;
bool visited[11][11];
bool isVisted(int a, int b){
    for(int i = 0;i<5;i++){
        int ny = a + dy[i];
        int nx = b + dx[i];
        if(visited[ny][nx]) return 1;
    }
    return 0;
}
void checkOne(int y, int x, bool c){
    for(int i = 0;i < 5;i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        visited[ny][nx] = c;
        if(c) cmpR += a[ny][nx];
        else cmpR -= a[ny][nx];
    }
}
int main(){
    cin >> N;
    for(int i = 0;i < N;i++){
        for(int j = 0;j < N;j++){
            cin >> a[i][j];
        }
    }
    for(int x1 = 1;x1 < N-1;x1++){
        for(int y1 = 1;y1 < N-1;y1++){
            checkOne(x1,y1,1);
            for(int x2 = 1;x2 < N-1;x2++){
                for(int y2 = 1;y2 < N-1;y2++){
                    if(isVisted(x2,y2) == 0) {
                        checkOne(x2,y2,1);
                        for(int x3 = 1;x3 < N-1;x3++){
                            bool flag3 = 0;
                            for(int y3 = 1;y3 < N-1;y3++){
                                if(isVisted(x3,y3) == 0) {
                                    checkOne(x3,y3,1);
                                    if(ret > cmpR){
                                        ret = min(ret, cmpR);
                                        // cout << "cmpR: "<< cmpR << " " << x1 << "," << y1 << " " << x2 << "," << y2 << " " << x3 << "," << y3 << "\n";
                                    }
                                    checkOne(x3,y3,0);
                                }
                            }
                        }
                        checkOne(x2,y2,0);
                    }
                }
            }
            checkOne(x1,y1,0);
        }
    }
    cout << ret;

    return 0;
}