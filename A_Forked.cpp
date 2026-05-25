#include <bits/stdc++.h>
using namespace std;

int dx[4]={-1,1,-1,1};
int dy[4]={-1,1, 1, -1};
int main(){
    int t; cin>>t;
    while(t--){
        long long a, b;//knights move
        cin>>a>>b;

        long long xking, yking; 
        cin>>xking>>yking;

        long long yqueen, xqueen;
        cin>>xqueen>>yqueen;

        set<pair<int,int>> king_hits, queen_hits;

        //all possible positions attacked by knight
        for(int j=0 ; j<4; j++){
            //attack king
            king_hits.insert({xking + dx[j]*a, yking + dy[j]*b});
            king_hits.insert({xking + dx[j]*b, yking + dy[j]*a});

            //attack queen
            queen_hits.insert({xqueen + dx[j]*a, yqueen + dy[j]*b});
            queen_hits.insert({xqueen + dx[j]*b, yqueen + dy[j]*a});
        }

        int ans =0;
        for(auto& pos:king_hits){
            if(queen_hits.count(pos)) ans++;
        }
        cout<<ans<<'\n';

    }
}