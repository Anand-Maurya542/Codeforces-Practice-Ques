// Author: Anand Maurya

#include <bits/stdc++.h>
using namespace std;
#define int long long

using ll = long long;
const int MOD = 1e9 + 7;


int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n ;

    if(n<3){
        cout<<n<<'\n';
        return 0;
    }

    vector<int> pos, ht;
    for(int i=0; i<n; i++){
        int a, b;
        cin>>a>>b;
        pos.push_back(a);
        ht.push_back(b);
    }
    
    int last = pos[0];
    int fall = 1;

    for(int i=1; i<n-1; i++){

        int xi = pos[i];
        int hi = ht[i];
        
        int left = xi-hi;
        int right = xi + hi;

        if(left > last){
            fall++;
            last = xi;
        }else if(right < pos[i+1]){
            fall++;
            last = right;
        }else last = xi;
        


    }
    cout<<fall+1<<'\n';





    return 0;
}