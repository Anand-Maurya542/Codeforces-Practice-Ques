#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> m(n);

    for(int &x:m)
        cin >> x;

    vector<long long> left(n), right(n);

    stack<int> st;

    // left contribution
    for(int i=0;i<n;i++){

        while(!st.empty() && m[st.top()]>=m[i])
            st.pop();

        if(st.empty())
            left[i]=1LL*(i+1)*m[i];
        else{
            int p=st.top();
            left[i]=left[p]+1LL*(i-p)*m[i];
        }

        st.push(i);
    }

    while(!st.empty()) st.pop();

    // right contribution
    for(int i=n-1;i>=0;i--){

        while(!st.empty() && m[st.top()]>=m[i])
            st.pop();

        if(st.empty())
            right[i]=1LL*(n-i)*m[i];
        else{
            int p=st.top();
            right[i]=right[p]+1LL*(p-i)*m[i];
        }

        st.push(i);
    }

    long long best=-1;
    int peak=0;

    for(int i=0;i<n;i++){

        if(left[i]+right[i]-m[i]>best){

            best=left[i]+right[i]-m[i];
            peak=i;
        }
    }

    vector<int> ans(n);

    ans[peak]=m[peak];

    for(int i=peak-1;i>=0;i--)
        ans[i]=min(m[i],ans[i+1]);

    for(int i=peak+1;i<n;i++)
        ans[i]=min(m[i],ans[i-1]);

    for(int x:ans)
        cout<<x<<" ";
}