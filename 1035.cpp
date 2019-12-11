#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second
#define mp make_pair

typedef pair<int, int> pii;

const int MAXN = 100;
int checked[MAXN + 5];
vector<int> primes;

void sieve(){
    for(int i = 2; i <= MAXN; ++i){
        if(!checked[i]){
            primes.pb(i);
            for(int j = i * i; j <= MAXN; j += i)
                checked[j] = 1;
        }
    }
}
int main(){
    sieve();
    int T;
    cin >> T;
    for(int tc = 1; tc <= T; ++tc){
        int n;
        cin >> n;
        int a[n + 1];
        for(int i = 1; i <= n; ++i) a[i] = i;
        cout << "Case " << tc << ": " << n << " = ";
        vector<pii> result;
        for(int prime : primes) {
            if(prime > n) break;
            int c = 0;
            for (int i = prime; i <= n; ++i) {
                while(a[i] % prime == 0){
                    c++;
                    a[i] /= prime;
                }
            }
            result.pb(mp(prime, c));
        }
        for(int i = 0; i < result.size(); ++i){
            pii r = result[i];
            if(i == result.size() - 1)
                cout << r.ff << " (" << r.ss << ")\n";
            else cout << r.ff << " (" << r.ss << ") * ";
        }
    }
    return 0;
}
