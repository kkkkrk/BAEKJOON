#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int N;
    vector<int> a;
    cin >> N;
    for(int i = 0;i < N;i++){
        int x;
        cin >> x;
        a.push_back(x);
    }
    for(int i = 0;i < N;i++){
        for(int j = 0;j < N - i-1;j++){
            if(a[j] > a[j+1]){
                int tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
        }
    }
    for(int i = 0;i < N;i++){
        cout << a[i] << "\n";
    }

    return 0;
}