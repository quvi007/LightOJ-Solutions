#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

int fx[] = {-1, 1, 0, 0}, fy[] = {0, 0, -1, 1};
int dp[502][502], visited[502][502];
char grid[502][502], str[502];

void bfs(pii v){
    queue<pii> q;
    q.push(v);
    visited[v.ff][v.ss] = 1;
    vector<pii> nodes;
    int ans = 0;
    while(!q.empty()){
        pii f = q.front();
        nodes.pb(f);
        q.pop();
        if(grid[f.ff][f.ss] == 'C') ans++;
        vector<pii> adj;
        for(int i = 0; i < 4; ++i){
            char ch = grid[f.ff + fx[i]][f.ss + fy[i]];
            if(ch != '#') adj.pb(mp(f.ff + fx[i], f.ss + fy[i]));
        }
        for(pii u : adj){
            if(!visited[u.ff][u.ss]){
                visited[u.ff][u.ss] = 1;
                q.push(u);
            }
        }
    }
    for(pii node : nodes){
        dp[node.ff][node.ss] = ans;
    }
}

int main(){
    int T, m, n, q, x, y;
    scanf("%d", &T);
    for(int tc = 1; tc <= T; ++tc){
        scanf("%d %d %d", &m, &n, &q);
        memset(grid, '#', sizeof grid);
        memset(dp, -1, sizeof dp);
        memset(visited, 0, sizeof visited);

        for(int i = 1; i <= m; ++i){
            scanf("%s", str);
            for(int j = 1; j <= n; ++j){
                grid[i][j] = str[j - 1];
            }
        }

        for(int i = 1; i <= m; ++i){
            for(int j = 1; j <= n; ++j){
                if(dp[i][j] == -1 && grid[i][j] != '#'){
                    bfs(mp(i, j));
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
