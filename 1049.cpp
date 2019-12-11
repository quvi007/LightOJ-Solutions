#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second
#define mp make_pair

typedef pair<int, int> pii;

int main() {
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        int n, ans = 0, ans1 = 0, ans2 = 0;
        cin >> n;
        vector<pii> adj[n + 1];
        for (int i = 0; i < n; ++i) {
            int a, b, c;
            cin >> a >> b >> c;
            adj[a].pb(mp(b, 0));
            adj[b].pb(mp(a, c));
        }
        int src = 1, f = 0, f_c = 0;
        vector<bool> visited(n + 1, false);
        vector<int> parent(n + 1);
        queue<int> q;
        q.push(src);
        parent[src] = src;
        visited[src] = true;
        while(1) {
            int v = q.front();
            q.pop();
            if(v == src && f_c != 0)
                break;
            f_c++;
            for (pii p : adj[v]) {
                int u = p.ff;
                if (f == 0) {
                    f = 1;
                    continue;
                }
                if (u != parent[v]) {
                    q.push(u);
                    ans1 += p.ss;
                    parent[u] = v;
                }
            }
        }
        f = f_c = 0;
        visited.assign(n + 1, false);
        q = queue<int>();
        parent.clear();
        q.push(src);
        parent[src] = src;
        visited[src] = true;
        reverse(adj[src].begin(), adj[src].end());
        while(1) {
            int v = q.front();
            q.pop();
            if(v == src && f_c != 0)
                break;
            f_c++;
            for (pii p : adj[v]) {
                int u = p.ff;
                if (f == 0) {
                    f = 1;
                    continue;
                }
                if (u != parent[v]) {
                    q.push(u);
                    ans2 += p.ss;
                    parent[u] = v;
                }
            }
        }
        ans = min(ans1, ans2);
        cout << "Case " << tc << ": " << ans << '\n';
    }
    return 0;
}
