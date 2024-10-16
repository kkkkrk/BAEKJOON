#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
int N;
vector<vector<bool>> v(130);
vector<int> cnt;
void paper(int x1, int y1,int x2, int y2){
    bool flag = v[x1][y1];
    int flag2 = 0;
    for(int i = x1;i < x2;i++){
        for(int j = y1;j < y2;j++){
            if(v[i][j] != flag){
                flag2 = 1;
            }
        }
    }
    
    if(flag2){
        paper(x1,y1,(x1+x2)/2,(y1+y2)/2);
        paper((x1+x2)/2,y1,x2,(y1+y2)/2);
        paper((x1+x2)/2,(y1+y2)/2,x2,y2);
        paper(x1,(y1+y2)/2,(x1+x2)/2,y2);
    }
    else{
        cnt[flag] += 1;
    }
}
int main()
{
    cin >> N;
    for(int i = 0;i < N;i++){
        for(int j = 0;j < N;j++){
            bool a;
            cin >> a;
            v[j].push_back(a);
        }
    }
    cnt.push_back(0);
    cnt.push_back(0);
    paper(0,0,N,N);
    cout << cnt[0] << "\n";
    cout << cnt[1];
    return 0;
}