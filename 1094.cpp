#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const ll INF = 1e18 + 5;

int main(){
    int T;
    scanf("%d", &T);
    for(int tc = 1; tc <= T; ++tc){
        int n;
        scanf("%d", &n);
        vector<pii> adj[n];
        for(int i = 1; i <= n - 1; ++i){
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            adj[u].pb(mp(-w, v));
            adj[v].pb(mp(-w, u));
        }
        priority_queue<pii> pq;
        int src = 0;
        vector<ll> d(n, INF);
        d[0] = 0;
        pq.push(mp(0, src));
        while(!pq.empty()){
            int v = pq.top().ss;
            pq.pop();
            for(pii p : adj[v]){
                int u = p.ss;
                if(d[u] > (d[v] - p.ff)) {
                    d[u] = d[v] - p.ff;
                    pq.push(p);
                }
            }
        }
        int idx = -1;
        ll nax = -1;
        for(int i = 0; i < n; ++i){
            if(d[i] > nax){
                nax = d[i];
                idx = i;
            }
        }
        src = idx;
        d = vector<ll>(n, INF);
        d[src] = 0;
        pq.push(mp(0, src));
        while(!pq.empty()){
            int v = pq.top().ss;
            pq.pop();
            for(pii p : adj[v]){
                int u = p.ss;
                if(d[u] > (d[v] - p.ff)){
                    d[u] = d[v] - p.ff;
                    pq.push(p);
                }
            }
        }
        nax = -1;
        for(ll x : d)
            nax = max(nax, x);
        cout << "Case " << tc << ": " << nax << '\n';
    }
    return 0;
}
