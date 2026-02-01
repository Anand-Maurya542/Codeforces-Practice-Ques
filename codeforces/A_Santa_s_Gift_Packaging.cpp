#include <iostream>
using namespace std;

void solve(){
    int l,b,h,s;
    cin>>l>>b>>h>>s;
    int cube=s*s*s;
    int cuboid=l*b*h;
    if(cube<cuboid) cout<<"CUBE\n";
    else if(cube==cuboid) cout<<"EQUAL\n";
    else cout<<"CUBOID\n";
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}

