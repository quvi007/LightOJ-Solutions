#include<bits/stdc++.h>
using namespace std;

const int M = 100000007;
int dp[10001];

int main(){
    int T;
    scanf("%d", &T);
    for(int tc = 1; tc <= T; ++tc){
        int n, k;
        scanf("%d %d", &n, &k);
        int A[n];
        for(int &u : A) scanf("%d", &u);
        memset(dp, 0, sizeof dp);
        dp[0] = 1;
        for(int i = 1; i <= n; ++i){
            for(int m = A[i - 1]; m <= k; ++m){
                (dp[m] += dp[m - A[i - 1]]) %= M;
            }
        }
        printf("Case %d: %d\n", tc, dp[k]);
    }
    return 0;
}
