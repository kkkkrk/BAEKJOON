#include <iostream>
#include <stack>
#include <queue>
#include <deque>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    deque<int> st;
    int N;
    cin >> N;
    
    for(int i = 0;i < N;i++){
        string s;
        cin >> s;
        if(s == "push_front"){
            int a;
            cin >> a;
            st.push_front(a);
        }
        else if(s == "push_back"){
            int a;
            cin >> a;
            st.push_back(a);
        }
        else if(s == "pop_front"){
            if (st.empty()) {
                cout << -1 << "\n"; // 스택이 비어있으면 -1 출력 (문제 조건에 따라 다를 수 있음)
            } else {
                cout << st.front() << "\n";
                st.pop_front();
            }
        }
        else if(s == "pop_back"){
            if (st.empty()) {
                cout << -1 << "\n"; // 스택이 비어있으면 -1 출력 (문제 조건에 따라 다를 수 있음)
            } else {
                cout << st.back() << "\n";
                st.pop_back();
            }
        }
        else if(s == "size"){
            cout << st.size() << "\n";
        }
        else if(s == "empty"){
            cout << st.empty() << "\n";
        }
        else if(s == "front"){
            if (st.empty()) {
                cout << -1 << "\n"; // 스택이 비어있으면 -1 출력 (문제 조건에 따라 다를 수 있음)
            } else {
                cout << st.front() << "\n";
            }
        }
        else if(s == "back"){
            if (st.empty()) {
                cout << -1 << "\n"; // 스택이 비어있으면 -1 출력 (문제 조건에 따라 다를 수 있음)
            } else {
                cout << st.back() << "\n";
            }
        }
    }
    
    
    return 0;
}