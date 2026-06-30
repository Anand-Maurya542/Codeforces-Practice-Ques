// Author: Anand Maurya

#include <bits/stdc++.h>
using namespace std;
#define int long long

using ll = long long;
const int MOD = 1e9 + 7;

int R = 2023, N = R*(R+1) / 2;

vector<vector<int>> diag(R);

void precompute(){
    int idx = 2;
    diag[0]={1};
    for(int i=1; i<R; i++){
        vector<int> temp(i+1);
        for(int j=0; j<=i; j++){
            temp[j] = idx*idx;

            if(j>0) temp[j]+=diag[i-1][j-1];
            idx++;
        }

        diag[i]=temp;
    }

}

void solve()
{
    int n;
    cin >> n ;


    
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    precompute();

    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}