    #include <bits/stdc++.h>
    using namespace std;
    int n, ret, a,x,f,l,sum;
    vector<int> v;
    int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL); cout.tie(NULL);
        cin >> n;
        for(int i = 0;i < n;i++){
            cin >> a;
            v.push_back(a);
        }
        cin >> x;
        sort(v.begin(),v.end());
        l = v.size() - 1;
        sum = v[f] + v[l];
        if(sum == x) ret += 1;
        while(f < l){
            if(sum >= x){
                l -= 1;
            }
            else{
                f += 1;
            }
            if(f >= l) break;
            sum = v[f] + v[l];
            if(sum == x) ret += 1;
        }
        if(n==1) ret = 0;
        cout << ret;
        return 0;
    }
