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
    int N, team;
    int win = 0;
    string s;
    map<int,int> mp;
    vector<string> v;
    cin >> N;
    for(int i = 0;i < N;i++){
        v.clear();
        cin >> team >> s;
        v = split(s, ":");
        if(team == 1) win += 1;
        else win -= 1;
        if(win > 0){
            mp[stoi(v[0])*60 + stoi(v[1])] = 1;
        }
        else if(win == 0){
            mp[stoi(v[0])*60 + stoi(v[1])] = 0;
        }
        else{
            mp[stoi(v[0])*60 + stoi(v[1])] = 2;
        }
        
    }
    if(win > 0){
        mp[48*60] = 1;
    }
    else if(win == 0){
        mp[48*60] = 0;
    }
    else{
        mp[48*60] = 2;
    }
    int cnt = 0;
    int team1 = 0;
    int team2 = 0;
    int previous = 0;
    for(auto it: mp){
        if(cnt == 1) team1 += it.first - previous;
        if(cnt == 2) team2 += it.first - previous;
        cnt = it.second;
        previous = it.first;
    }
    if(team1/60 == 0) cout << "00" << ":";
    else if(team1/60 < 10) cout << 0 << team1/60 << ":";
    else cout << team1 / 60 <<":";
    if(team1%60 == 0) cout << "00";
    else if(team1%60 < 10) cout << 0 << team1%60;
    else cout << team1 % 60;
    cout << "\n";
    if(team2/60 == 0) cout << "00" << ":";
    else if(team2/60 < 10) cout << 0 << team2/60 << ":";
    else cout << team2 / 60 <<":";
    if(team2%60 == 0) cout << "00";
    else if(team2%60 < 10) cout << 0 << team2%60;
    else cout << team2 % 60;
    return 0;
}