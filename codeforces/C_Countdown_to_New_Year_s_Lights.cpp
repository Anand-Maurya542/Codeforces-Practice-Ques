#include <iostream>
using namespace std;

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int d=0,p=0;
    for(int i=0;i<n;i++){

        if(s[i]=='A' ||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'){
            p=i;
            break;

        }

    }
    for(int i=0;i<n;i++){

        if(s[i]=='A' ||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'){
            d=max(d,i-p);
            p=i;

        }
        

    }
    cout<<d<<"\n";
    
   
}
int main(){
    long long t;
    cin>>t;
    while(t--){
        solve();
    }
}