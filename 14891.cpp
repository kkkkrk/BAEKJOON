#include <bits/stdc++.h>
using namespace std;
vector<deque<int>> v;
int K, a, b_inp, result;
bool b;

void turn(int idx, bool isclock){
    if(isclock == 1){
        v[idx].push_front(v[idx].back());
        v[idx].pop_back();
    }
    else{
        v[idx].push_back(v[idx].front());
        v[idx].pop_front();
    }
}
int main(){
    deque<int> d;
    for(int i = 0;i < 4;i++){
        v.push_back(d);
    }
    for(int i = 0;i < 4;i++){
        string s;
        cin >> s;
        for(char c: s) v[i].push_back(c == '1');
    }
    cin >> K;
    bool dif01 = v[0][2] != v[1][6];
    bool dif12 = v[1][2] != v[2][6];
    bool dif23 = v[2][2] != v[3][6];
    for(int i = 0;i < K;i++){
        cin >> a >> b_inp;
        a -= 1;
        if(b_inp == 1) b = 1;
        else b = 0;
        if(a == 0){
            turn(0, b);
            if(dif01){
                turn(1, !b);
                if(dif12){
                    turn(2, b);
                    if(dif23){
                        turn(3, !b);
                    }
                }
            }
        }
        else if(a == 1){
            turn(1, b);
            if(dif12){
                turn(2, !b);
                if(dif23){
                    turn(3, b);
                }
            }
            if(dif01) {
                turn(0, !b);      
            }
        }
        else if(a == 2){
            turn(2, b);
            if(dif12){
                turn(1, !b);
                if(dif01){
                    turn(0, b);
                }
            }
            if(dif23) {
                turn(3, !b);   
            }
        }
        else{
            turn(3, b);
            if(dif23){
                turn(2, !b);
                if(dif12){
                    turn(1, b);
                    if(dif01){
                        turn(0, !b);
                    }
                }
            }
        }
        dif01 = v[0][2] != v[1][6];
        dif12 = v[1][2] != v[2][6];
        dif23 = v[2][2] != v[3][6];
    }
    if(v[0][0]) result += 1;
    if(v[1][0]) result += 2;
    if(v[2][0]) result += 4;
    if(v[3][0]) result += 8;
    cout << result;
    return 0;
}