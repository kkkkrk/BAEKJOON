#include <bits/stdc++.h>
using namespace std;
vector<string> split(const string & input, string delimeter){
    auto start = 0;
    auto end = input.find(delimeter);
    vector<string> result;
    while(end != string::npos){
        result.push_back(input.substr(start, end - start));
        start = end + delimeter.size();
        end = input.find(delimeter, start);
    }
    result.push_back(input.substr(start));
    return result;
}
int main(){
    string s;
    int cnt = 0;
    getline(cin, s);
    vector<string> result = split(s, " ");
    for(string ss: result){
        if(ss != "") cnt++;
    }
    cout << cnt;
    return 0;
}