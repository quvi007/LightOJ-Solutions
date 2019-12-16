#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int M = 1e4 + 56;
const int MAXN = 1e3;

int dp[MAXN + 5];
ll dp2[MAXN + 5][MAXN + 5];

ll nCr(int n, int r){
    if(r == 0) return 1;
    if(n == r) return 1;
    if(dp2[n][r] != -1) return dp2[n][r];
    ll ans = (nCr(n - 1, r - 1) + nCr(n - 1, r)) % M;
    return dp2[n][r] = ans;
}

int getAns(int n){
    if(n == 0) return 1;
    if(dp[n] != -1) return dp[n];
    int ans = 0;
    for(int i = 1; i <= n; ++i){
        ans = (ans + (nCr(n, i) * (getAns(n - i) % M)) % M) % M;
    }
    return dp[n] = ans;
}

int main(){
    memset(dp, -1, sizeof dp);
    memset(dp2, -1, sizeof dp2);
    int T;
    scanf("%d", &T);
    for(int tc = 1; tc <= T; ++tc){
        int n;
        scanf("%d", &n);
        printf("Case %d: %d\n", tc, getAns(n));
    }
    return 0;
}
