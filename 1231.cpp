#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M = 100000007;
int main(){
    int T;
    cin >> T;
    for(int tc = 1; tc <= T; ++tc){
        int n, k;
        cin >> n >> k;
        vector<int> A(n), C(n);
        for(int &u : A) cin >> u;
        for(int &u : C) cin >> u;
        vector<vector<ll>> dp(n + 1, vector<ll>(k + 1, 0));
        dp[0][0] = 1;
        for(int i = 1; i <= n; ++i){
            for(int m = 0; m <= k; ++m){
                for(int j = 0; j <= C[i - 1]; ++j){
                    if(A[i - 1] * j > m) break;
                    (dp[i][m] += dp[i - 1][m - A[i - 1] * j]) %= M;
                }
            }
        }
        cout << "Case " << tc << ": " << dp[n][k] << '\n';
    }
    return 0;
}
