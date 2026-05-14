#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int x,y,a,b;
        cin>>x>>y>>a>>b;

        if(a==x && y==b) {
            cout<<0<<'\n';
            continue;
        }

        if(y>b){ //not possible
                cout<<-1<<'\n';
                continue;
        }

        int moves=b-y;
        int xmoves=x+moves;
        
        if(xmoves<a) cout<<-1<<"\n";
        else cout<<moves+xmoves-a<<"\n";

        
    }
}