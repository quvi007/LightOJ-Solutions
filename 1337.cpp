#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

map<pii, bool> visited;
int fx[] = {-1, 1, 0, 0}, fy[] = {0, 0, -1, 1};
int dp[502][1002];
char grid[502][1002], str[1002];
vector<pii> nodes;

int dfs(pii v){
    visited[v] = true;
    vector<pii> adj;
    nodes.pb(v);
    for(int i = 0; i < 4; ++i){
        char ch = grid[v.ff + fx[i]][v.ss + fy[i]];
        if(ch != '#') adj.pb(mp(v.ff + fx[i], v.ss + fy[i]));
    }
    int ans = 0;
    for(pii u : adj)
        if(!visited[u])
            ans += dfs(u);
    if(grid[v.ff][v.ss] == 'C') ans++;
    return ans;
}

int main(){
    int T, m, n, q, x, y;
    scanf("%d", &T);
    for(int tc = 1; tc <= T; ++tc){
        scanf("%d %d %d", &m, &n, &q);
        memset(grid, '#', sizeof grid );
        memset(dp, -1, sizeof dp);
        visited.clear();
        nodes.clear();
        for(int i = 1; i <= m; ++i){
            scanf("%s", str);
            for(int j = 1; j <= n; ++j){
                grid[i][j] = str[j - 1];
            }
        }
        for(int i = 1; i <= m; ++i){
            for(int j = 1; j <= n; ++j){
                if(dp[i][j] == -1 && grid[i][j] != '#'){
                    nodes.clear();
                    int r = dfs({i, j});
                    for(pii node : nodes){
                        dp[node.ff][node.ss] = r;
                    }
                }
            }
        }
        printf("Case %d:\n", tc);
        for(int i = 0; i < q; ++i){
            scanf("%d %d", &x, &y);
            printf("%d\n", dp[x][y]);
        }
    }
    return 0;
}
