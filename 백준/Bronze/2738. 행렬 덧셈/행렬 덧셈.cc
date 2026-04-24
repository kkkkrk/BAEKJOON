#include <iostream>
using namespace std;

int main() {
    int N, M,a[101][101];
    cin >> N >> M;
    for(int i = 0;i < N;i++){
        for(int j = 0;j < M;j++){
            cin >> a[i][j];
        }
    }
    for(int i = 0;i < N;i++){
        for(int j = 0;j < M;j++){
            int k;
            cin >> k;
            cout << a[i][j] + k << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}