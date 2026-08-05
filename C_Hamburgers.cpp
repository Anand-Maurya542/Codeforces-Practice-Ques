// Author: Anand Maurya

#include <bits/stdc++.h>
using namespace std;
#define int long long

using ll = long long;
const int MOD = 1e9 + 7;


string str;
int b , s, c;
int cb, cs, cc;
int mm; 
int nb=0, ns=0, nc=0;

bool valid(int mid){
    int m = mm;

    if(b<mid*nb){
        int need = mid*nb - b;
        if(need*cb>m) return false;
        m -= need*cb;
    }
    if(s < mid * ns){
        int need = mid * ns-s;
        if(need * cs > m) return false;
        m -= need*cs;
    }
    if(c < mid * nc){
        int need = mid * nc - c;
        if(need * cc > m) return false;
    }
    return true;
}


int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>str;
    cin>>b>>s>>c;
    cin>>cb>>cs>>cc;
    cin>>mm;

    for(char& ch : str){
        if(ch=='B') nb++;
        else if(ch=='S') ns++;
        else if(ch=='C')nc++;
    }

    int lo = 0, hi = mm + 100;

    int ans = 0;
    while(lo<=hi){
        int mid = lo + (hi-lo)/2;
        if(valid(mid)){
            ans = mid;
            lo = mid +1;
        }else hi = mid-1;
    }
    cout<<ans<<'\n';






    return 0;
}