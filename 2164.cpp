#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
int main()
{
    int N;
    cin >> N;
    queue<int> q;
    for(int i = 1;i <= N;i++){
        q.push(i);
    }
    bool flag = 1;
    while(q.size()>1){
        if(flag){
            q.pop();
            flag = 0;
        }
        else{
            q.push(q.front());
            q.pop();
            flag = 1;
        }
    }
    cout << q.front();
    return 0;
}