#include <iostream>
using namespace std;

void solve(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int g=0,l=0;
    for(int i=0;i<s.size() && k>0;i++){
        if(s[i]=='N' && k>0){
            k--;
        }
        else g++;
        l++;
    }
    for(int i=l;i<s.size();i++){
        if(s[i]=='N') break;
        else g++;
    }
    cout<<g<<"\n";
}
int main(){
    long long t;
    cin>>t;
    while(t--){
        solve();
    }
}