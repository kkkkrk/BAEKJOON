#include <iostream>
using namespace std;
int main()
{
    int N, num[100000];
    cin >> N;
    for (int i = 0;i < N;i++){
        int A, B;
        cin >> A >> B;
        num[i] = A+B;
    }
    
    for(int i = 0;i < N;i++){
        cout << num[i] << endl;
    }

    return 0;
}