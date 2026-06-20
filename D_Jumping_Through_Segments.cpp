// Author: Anand Maurya

#include <bits/stdc++.h>
using namespace std;
#define int long long

using ll = long long;
const int MOD = 1e9 + 7;
vector<pair<int,int>> arr;
int n;

bool check(int mid){
    int currMin = 0;
    int currMax = 0;

    for(int i=0; i<n; i++){
        auto& [start, end] = arr[i];

        currMin -= mid;
        currMax +=mid;

        //intersection
        int recStart = max(currMin, start);
        int recEnd = min(currMax, end);

        //empty -> intersectio

        if(recStart > recEnd) return false;
        
        currMin = recStart;
        currMax = recEnd;
    }
    return true;
}

void solve()
{
    cin >> n ;
    arr.resize(n);
    for(int i=0; i<n; i++){
        int a,b;
        cin>>a>>b;
        arr[i]={a,b};
    }

    int lo = 0, hi = 1e9;
    int ans = -1;

    while(lo<=hi){
        int mid = lo + (hi-lo)/2;

        if(check(mid)){
            ans = mid;
            hi=mid-1;


        }else lo=mid+1;

        

    }
    cout<<ans<<'\n';

    
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