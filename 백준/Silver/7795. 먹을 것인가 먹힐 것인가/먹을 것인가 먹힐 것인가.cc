#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    int T;
    vector<int> A;
    vector<int> B;
    vector<int> result;
    cin >> T;
    for(int i = 0;i < T;i++){
        int N,M;
        cin >> N >> M;
        int a;
        int re = 0;
        int cnt = 0;
        A.clear();
        B.clear();
        for(int j = 0;j < N;j++){
            cin >> a;
            A.push_back(a);
        }
        for(int j = 0;j < M;j++){
            cin >> a;
            B.push_back(a);
        }
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        for(int j =0;j < M;j++){
            if(B[j] < A[cnt]){
                re += N - cnt;
            }
            else{
                cnt += 1;
                if(cnt == N) break;
                j -= 1;
            }
            
        }
        result.push_back(re);
    }
    for(int i = 0;i < result.size();i++){
        cout << result[i] << endl;
    }
    
    return 0;
}