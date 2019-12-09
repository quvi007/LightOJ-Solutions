#include<bits/stdc++.h>
using namespace std;

#define pb push_back

vector<int> c;
vector<bool> visited;
vector<vector<int>> adj;

void dfs(int v){
    visited[v] = true;
    c[v]++;
    for(int u : adj[v]){
        if(!visited[u]){
            dfs(u);
        }
    }
}
int main(){
    int T;
    cin >> T;
    for(int tc = 1; tc <= T; ++tc){
        int k, n, m;
        cin >> k >> n >> m;
        vector<int> persons(k);
        adj = vector<vector<int>>(n + 1);
        c = vector<int>(n + 1, 0);
        for(int i = 0; i < k; ++i)
            cin >> persons[i];
        for(int i = 0; i < m; ++i){
            int u, v;
            cin >> u >> v;
            adj[u].pb(v);
        }
        for(int v : persons){
            visited = vector<bool>(n + 1, false);
            dfs(v);
        }
        int ans = 0;
        for(int i = 1; i <= n; ++i)
            if(c[i] == k) ++ans;
        cout << "Case " << tc << ": " << ans << '\n';
    }
    return 0;
}
