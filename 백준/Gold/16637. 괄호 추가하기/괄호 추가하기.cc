#include <bits/stdc++.h>
using namespace std;
int N;
bool a[12];
string inp;
deque<int> s;
deque<char> ss;
int ret = -INT_MAX;
void f(int cnt){
    if(cnt > N/2 - 1){
        int cmp;
        s.clear();
        ss.clear();
        s.push_back(int(inp[0] - '0'));
        for(int i = 0;i < N/2;i++){
            int opt = (i+1)*2 - 1;
            if(a[i]){
                int t = s.back(); s.pop_back();
                if(inp[opt] == '+') s.push_back(t + int(inp[opt + 1] - '0'));
                else if(inp[opt] == '-') s.push_back(t - int(inp[opt + 1] - '0'));
                else if(inp[opt] == '*') s.push_back(t * int(inp[opt + 1] - '0'));
            }
            else{
                ss.push_back(inp[opt]);
                s.push_back(int(inp[opt + 1] - '0'));
            }
        }
        cmp = s.front(); s.pop_front();
        while(s.size()){
            int aa = s.front(); s.pop_front();
            if(ss.front() == '+') cmp = cmp + aa;
            else if(ss.front() == '-') cmp = cmp - aa;
            else if(ss.front() == '*') cmp = cmp * aa;
            ss.pop_front();
        }
        ret = max(ret, cmp);
        return;
    }
    a[cnt] = 1;
    f(cnt + 2);
    a[cnt] = 0;
    f(cnt + 1);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    cin >> inp;
    f(0);
    cout << ret;
    return 0;
}