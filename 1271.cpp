#include<bits/stdc++.h>
using namespace std;

#define pb push_back

const int MAXN = 50005;
int d[MAXN], p[MAXN], visited[MAXN];

int main() {
    int T;
    scanf("%d", &T);
    for(int tc = 1; tc <= T; ++tc){
        int n;
        scanf("%d", &n);
        int nodes[n];
        scanf("%d", &nodes[0]);
        vector<int> adj[MAXN];
        for(int i = 1; i < n; ++i){
            scanf("%d", &nodes[i]);
            adj[nodes[i - 1]].pb(nodes[i]);
            adj[nodes[i]].pb(nodes[i - 1]);
        }
        for(int i = 0; i < n; ++i){
            sort(adj[nodes[i]].begin(), adj[nodes[i]].end());
        }
        queue<int> q;
        memset(d, 0, sizeof d);
        memset(p, -1, sizeof p);
        memset(visited, 0, sizeof visited);

        d[nodes[0]] = 0;
        visited[nodes[0]] = 1;
        p[nodes[0]] = -1;
        q.push(nodes[0]);
        while(!q.empty()){
            int v = q.front();
            q.pop();
            for(int u : adj[v]){
                if(!visited[u]){
                    visited[u] = 1;
                    d[u] = d[v] + 1;
                    q.push(u);
                    p[u] = v;
                }
            }
        }
        vector<int> path;
        for(int x = nodes[n - 1]; x != -1; x = p[x]){
            path.pb(x);
        }
        reverse(path.begin(), path.end());
        printf("Case %d:\n", tc);
        for(int i = 0; i < path.size(); ++i) {
            if(i) printf(" %d", path[i]);
            else printf("%d", path[i]);
        }
        printf("\n");
    }
    return 0;
}
