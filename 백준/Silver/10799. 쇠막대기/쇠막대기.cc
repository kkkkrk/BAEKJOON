#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int count= 0;
    int answer = 0;
    for(int i = 0;i < s.size();i++){
        if(s[i] == '('){
            count = count + 1;
        }
        else if(s[i] == ')'){
            count = count - 1;
            if(s[i-1] == '('){
                answer = answer + count;
            }
            else{
                answer += 1;
            }
        }
    }
    cout << answer;
    
    return 0;
}