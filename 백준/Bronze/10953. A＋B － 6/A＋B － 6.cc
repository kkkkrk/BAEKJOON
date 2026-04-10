#include <bits/stdc++.h>
using namespace std;
vector<string> split(const string &input, string delimeter){
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
    int N;
    string s;
    cin >> N;
    for(int i = 0;i < N;i++){
        cin >> s;
        vector<string> s1 = split(s, ",");
        cout << stoi(s1[0]) + stoi(s1[1]) << "\n";
    }
    
    return 0;
}