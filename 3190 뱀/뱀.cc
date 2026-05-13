#include <bits/stdc++.h>
using namespace std;
int n, k, l, ret, aa,bb,chk,ny,nx;
bool a[102][102];
char cc;
int dy[] = {0,1,0,-1};
int dx[] = {1,0,-1,0};
vector<pair<int,char>> v;
deque<pair<int,int>> dq;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    for(int i = 0;i < k;i++){
        cin >> aa >> bb;
        a[aa][bb] = 1;
    }
    cin >> l;
    for(int i = 0;i < l;i++){
        cin >> aa >> cc;
        v.push_back({aa,cc});
    }
    sort(v.begin(), v.end());
    dq.push_back({1,1});
    int idx = 0;
    chk = 0;
    for(int t = 1;t <= n*n+1;t++){
        if(idx < v.size() && v[idx].first == t-1){
            if(v[idx].second == 'L'){
                chk = (chk + 3) % 4;
            }
            else{
                chk = (chk + 1) % 4;
            }
            idx++;
        }
        tie(ny,nx) = dq.front();
        ny += dy[chk];
        nx += dx[chk];
        if(ny > n || ny <= 0 || nx > n || nx <= 0){
            cout << t;
            return 0;
        }
        for(int i = 0;i < dq.size();i++){
            if(ny == dq[i].first && nx == dq[i].second){
                cout << t;
                return 0;
            }
        }
        dq.push_front({ny,nx});
        if(!a[ny][nx]){
            dq.pop_back();
        }
    }
    return 0;
}
