#include<bits/stdc++.h>
using namespace std;

#define pb push_back

int bfs(int s, int e, int N, vector<vector<int>> adj){
    queue<int> q;
    vector<int> d(N, 0);
    vector<bool> visited(N, false);
    d[s] = 0;
    q.push(s);
    visited[s] = true;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int u : adj[v]){
            if(!visited[u]){
                visited[u] = true;
                d[u] = d[v] + 1;
                q.push(u);
            }
        }
    }
    return d[e];
}
int main(){
    int T;
    cin >> T;
    for(int tc = 1; tc <= T; ++tc){
        int N, R;
        cin >> N;
        cin >> R;
        vector<vector<int>> adj(N);
        for(int r = 1; r <= R; ++r){
            int u, v;
            cin >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        int s, d;
        cin >> s >> d;
        int ans = -1;
        for(int i = 0; i < N; ++i){
            ans = max(ans, bfs(s, i, N, adj) + bfs(i, d, N, adj));
        }
        cout << "Case " << tc << ": " << ans << '\n';
    }
    return 0;
}
