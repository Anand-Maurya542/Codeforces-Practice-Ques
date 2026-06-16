// Author: Anand Maurya

#include <bits/stdc++.h>
using namespace std;
#define int long long

using ll = long long;
const int MOD = 1e9 + 7;

void solve()
{
    int n, k,m;
    cin >> n >> k >> m;
    string s;
    cin>>s;

    vector<bool> found(k,false);
    int cnt = 0;
    string res ="";

    for(char ch:s){
        if(res.size()==n) break;
        if(!found[ch-'a']){
            cnt++;
        }
        found[ch-'a']=true;

        if(cnt == k){
            cnt = 0;
            res.push_back(ch);
            fill(found.begin(), found.end(), false);
        }
    }
    if(res.size() == n) cout<<"YES"<<'\n';
    else{
        for(int i=0; i<k; i++){
            if(!found[i]){
                while(res.size() < n){
                    res.push_back(i+'a');
                }
            }
        }
        cout<<"NO"<<'\n';
        cout<<res<<'\n';
    }

    
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}