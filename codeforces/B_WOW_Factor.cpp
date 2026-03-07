#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    long long w = 0;
    long long wo = 0;
    long long wow = 0;

    for(int i = 1; i < s.size(); i++){
        
        if(s[i] == 'v' && s[i-1] == 'v'){
            w++;
            wow += wo;
        }

        if(s[i] == 'o'){
            wo += w;
        }
    }

    cout << wow;
}