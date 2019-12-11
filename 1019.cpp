#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
typedef pair<int, int> pii;

const int INF = 1e9 + 5;

int main(){
    int T;
    cin >> T;
    for(int tc = 1; tc <= T; ++tc){
        int n, m;
        cin >> n >> m;
        vector<pii> adj[n + 1];
        vector<int> cost(n + 1, INF);
        for(int i = 0; i < m; ++i){
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].pb(mp(-w, v));
            adj[v].pb(mp(-w, u));
        }
        priority_queue<pii> pq;
        pii src = mp(0, 1);
        cost[src.ss] = 0;
        pq.push(src);
        while(!pq.empty()){
            pii v = pq.top();
            pq.pop();
            for(pii u : adj[v.ss]){
                if((cost[v.ss] - u.ff) < cost[u.ss]){
                    cost[u.ss] = cost[v.ss] - u.ff;
                    pq.push(u);
                }
            }
        }
        if(cost[n] == INF) cout << "Case " << tc << ": Impossible\n";
        else cout << "Case " << tc << ": " << cost[n] << '\n';
    }
    return 0;
}
