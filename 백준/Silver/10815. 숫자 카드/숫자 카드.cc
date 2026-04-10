#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> n;
vector<int> m;
vector<bool> index;

int main()
{
    for(int i = 0;i < 20000999;i++){
        index.push_back(false);
    }
    
    cin >> N;
    for(int i = 0;i < N;i++){
        int a;
        cin >> a;
        n.push_back(a);
    }
    
    cin >> M;
    for(int i = 0;i < M;i++){
        int a;
        cin >> a;
        m.push_back(a);
    }
    for(int i = 0;i < N;i++){
        if(n[i] >= 0){
            index[n[i]] = true;
        }
        else{
            index[10000100 - n[i]] = true;
        }
    }
    
    for(int i = 0;i < M;i++){
        if(m[i] >= 0){
            cout << index[m[i]] << ' ';
        }
        else{
            cout << index[10000100 - m[i]] << ' ';
        }
    }

    return 0;
}
