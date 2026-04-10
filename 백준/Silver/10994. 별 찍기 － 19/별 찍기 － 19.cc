#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<vector<char>> v;
    vector<char> v1;
    v.push_back(v1);
    for(int i = 0;i < (N-1)*4;i++){
        v.push_back(v1);
    }
    for(int i = 0;i < (N-1)*4 + 1;i++){
        for(int j = 0;j < (N-1)*4 + 1;j++){
            v[i].push_back(' ');
        }
    }
    v[(N-1)*2][(N-1)*2] = '*';
    for(int i = 0;i < N-1;i++){
        for(int j = i*2;j < v.size() - (i*2);j++){
            v[i*2][j] = '*';
        }
        for(int j = i*2;j < v.size() - (i*2);j++){
            v[v.size() - 1 - i*2][j] = '*';
        }
        for(int j = i*2;j < v.size() - (i*2);j++){
            v[j][i*2] = '*';
        }
        for(int j = i*2;j < v.size() - (i*2);j++){
            v[j][v.size() - 1 - i*2] = '*';
        }
    }
    for(int i = 0;i <v.size();i++){
        for(int j = 0;j < v.size();j++){
            cout << v[i][j];
        }
        cout << endl;
    }


    return 0;
}
