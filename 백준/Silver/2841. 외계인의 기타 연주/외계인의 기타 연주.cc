#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N, P, count = 0;
    vector<vector<int>> guitar;
    vector<int> v;
    cin >> N >> P;
    v.push_back(-1);
    for(int i = 0;i < 6;i++){
        guitar.push_back(v);
    }
    for(int i = 0;i < N;i++){
        int a, b;
        cin >> a >> b;
        if(guitar[a-1].back() < b){
            count += 1;
            guitar[a-1].push_back(b);
        }
        else if(guitar[a-1].back() > b){
            while(1){
                guitar[a-1].pop_back();
                count += 1;
                if(guitar[a-1].back() == b){
                    break;
                }
                else if(guitar[a-1].back() < b){
                    guitar[a-1].push_back(b);
                    count += 1;
                    break;
                }
            }
        }
    }
    cout << count;




    return 0;
}