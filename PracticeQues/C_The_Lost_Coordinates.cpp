    #include <bits/stdc++.h>
    using namespace std;

    vector<bool> isprime;
    void sieve(int n){
        isprime.assign(n+1,true);
        isprime[0]=isprime[1]=false;
        for(int i=2;i*i<=n;i++){
            if(isprime[i]){
                for(int j=i*i;j<=n;j+=i){
                    isprime[j]=false;
                }
            }
        }

    }
int toNumber(const string &s) {
    if (s.empty()) return -1;
    if (s.size() > 1 && s[0] == '0') return -1; // Leading zero
    int num = 0;
    for (char c : s) {
        num = num * 10 + (c - '0');
        if (num > 1000000) return -1; // Exceeds sieve limit
    }
    return num;
}
    int main() {
        string S;
        cin >> S;
        sieve(1000000);

        sort(S.begin(), S.end());

        long long countValid = 0;
        int n = S.size();

        do {
            // Try all ways to split into 4 parts
            for (int i = 1; i <= n - 3; i++) {
                for (int j = i + 1; j <= n - 2; j++) {
                    for (int k = j + 1; k <= n - 1; k++) {

                        string p1 = S.substr(0, i);
                        string p2 = S.substr(i, j - i);
                        string p3 = S.substr(j, k - j);
                        string p4 = S.substr(k);

                        // Check leading zero
                        if ((p1.size() > 1 && p1[0] == '0') ||
                            (p2.size() > 1 && p2[0] == '0') ||
                            (p3.size() > 1 && p3[0] == '0') ||
                            (p4.size() > 1 && p4[0] == '0'))
                            continue;

                        long long a = toNumber(p1);
                        long long b = toNumber(p2);
                        long long c = toNumber(p3);
                        long long d = toNumber(p4);

                        if (isprime[a] && isprime[b] &&
                            isprime[c] && isprime[d]) {
                            countValid++;
                        }
                    }
                }
            }

        } while (next_permutation(S.begin(), S.end()));

        cout << countValid << endl;
    }