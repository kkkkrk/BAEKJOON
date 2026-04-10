#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int H, W;
    cin >> H >> W;
    string s;
    vector<vector<bool>> cloud(H, vector<bool>(W));
    vector<vector<int>> v(H, vector<int>(W));
    for(int i = 0;i < H;i++){
        cin >> s;
        for(int j = 0;j < W;j++){
            if(s[j] == 'c') cloud[i][j] = 1;
            else cloud[i][j] = 0;
        }
    }
    for(int i = 0;i < H;i++){
        for(int j = 0;j < W;j++){
            if(cloud[i][j]) v[i][j] = 0;
            else{
                if(j == 0) v[i][j] = -1;
                else{
                    if(v[i][j-1] == -1) v[i][j] = -1;
                    else{
                        v[i][j] = v[i][j-1] + 1;
                    }
                }
            }
        }
    }
    for(int i = 0;i < H;i++){
        for(int j = 0;j < W;j++){
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}