// Author: Anand Maurya

#include <bits/stdc++.h>
using namespace std;
#define int long long

using ll = long long;
const int MOD = 1e9 + 7;


void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int &x:a) cin>>x;


    int lo = 0, hi = *min_element(a.begin(), a.end());

    if(k==0){
        cout<<hi<<'\n';
        return;    
    }

    if(k>=3){
        cout<<0<<'\n';
        return;
    }
    int ans = hi;
    
    vector<int> diff;
    for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			diff.push_back(abs(a[i] - a[j]));
		}
	}

    sort(diff.begin(), diff.end());

    ans=min(ans, diff[0]);

    if(k==2){
        //1st step me koi sa d append karna hai
        //second me har element se uss d difference lelo
        // |ai - d| ko minimize krna hai, aisa d select karo jo ai ke close ho

        for(int i=0; i<n; i++){
            auto it = lower_bound(diff.begin(), diff.end(), a[i]);

            if(it!=diff.end()){
                ans = min(ans, abs(*it-a[i]));
            }
            if(it!=diff.begin()){
                --it;
                ans=min(ans, abs(*it-a[i]));
            }
        }
        
        
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