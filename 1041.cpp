#include<bits/stdc++.h>
using namespace std;

#define pb push_back

struct Edge{
    string u, v;
    int w;
    bool operator<(Edge const& other){
        return w < other.w;
    }
};

map<string, string> parent;
map<string, bool> used;
set<string> cities;
map<string, bool> visited;
map<string, vector<string>> adj;

void make_set(string v){
    parent[v] = v;
}

string find_rep(string v){
    if(v == parent[v]) return v;
    return parent[v] = find_rep(parent[v]);
}

void union_set(string u, string v){
    u = find_rep(u);
    v = find_rep(v);
    if(u != v){
        parent[v] = u;
    }
}

int dfs(string v){
    visited[v] = true;
    int c = 1;
    for(string u : adj[v]){
        if(!visited[u]){
            c += dfs(u);
        }
    }
    return c;
}

int main(){
    int T;
    cin >> T;
    for(int tc = 1; tc <= T; ++tc){
        parent.clear();
        used.clear();
        cities.clear();
        visited.clear();
        adj.clear();
        int m, w, ans = 0;
        cin >> m;
        vector<Edge> edges;
        string city1, city2;
        for(int i = 0; i < m; ++i){
            cin >> city1 >> city2;
            if(!used[city1]) make_set(city1), used[city1] = 1, cities.insert(city1);
            if(!used[city2]) make_set(city2), used[city2] = 1, cities.insert(city2);
            cin >> w;
            if(w == 0){
                union_set(city1, city2);
                adj[city1].pb(city2);
                adj[city2].pb(city1);
            } else{
                Edge edge;
                edge.u = city1;
                edge.v = city2;
                edge.w = w;
                edges.pb(edge);
            }
        }
        sort(edges.begin(), edges.end());
        for(Edge edge : edges){
            string u = edge.u;
            string v = edge.v;
            if(find_rep(u) != find_rep(v)){
                union_set(u, v);
                adj[u].pb(v);
                adj[v].pb(u);
                ans += edge.w;
            }
        }
        int c = dfs(city1);
        bool flag = false;
        if(c == cities.size()) flag = true;
        if(flag) cout << "Case " << tc << ": " << ans << '\n';
        else cout << "Case " << tc << ": Impossible\n";
    }
    return 0;
}
