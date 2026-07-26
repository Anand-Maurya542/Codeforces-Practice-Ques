// Author: Anand Maurya

#include <bits/stdc++.h>
using namespace std;
#define int long long

using ll = long long;
const int MOD = 1e9 + 7;

int dist(int a, int b,int c, int d ){
    return abs(a-c) + abs(b-d);
}

void solve()
{
    vector<string> mat, v;
    mat.push_back("ABCD");
    mat.push_back("EFGH");
    mat.push_back("IJKL");
    mat.push_back("MNO.");
    map<char, pair<int,int>> mp;
    char ch = 'A';
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){

            mp[ch]={i,j};ch++;
        }
    }
    mp['.']={3,3};



    for(int i=0; i<4; i++){
        string s;
        cin>>s;
        v.push_back(s);

    }

    int cost = 0;
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){

            if(v[i][j]!=mat[i][j]){
                auto& [a,b]=mp[v[i][j]];
                // cout<<i<<j<<'\n';
                // cout<<a<<b<<'\n';

                cost += dist(i,j,a,b);
            }
        }
    }
    cout<<cost<<'\n';


    
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--)
        solve();

    return 0;
}