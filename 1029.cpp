#include<bits/stdc++.h>
using namespace std;

#define pb push_back

struct Edge{
    int u, v, w;
    bool operator<(Edge const& other){
        return w < other.w;
    }
};

vector<int> parent;


void make_set(int v){
    parent[v] = v;
}

void init_dsu(int n){
    for(int i = 0; i <= n; ++i){
        make_set(i);
    }
}

int find_rep(int v){
    if(v == parent[v]) return v;
    return parent[v] = find_rep(parent[v]);
}

void union_set(int u, int v){
    u = find_rep(u);
    v = find_rep(v);
    if(u != v){
        parent[u] = v;
    }
}

int main(){
    int T;
    cin >> T;
    for(int tc = 1; tc <= T; ++tc){
        int n;
        cin >> n;
        int u, v, w;
        vector<Edge> edges;
        while(cin >> u >> v >> w && !(u == 0 && v == 0 && w == 0)){
            Edge edge;
            edge.u = u;
            edge.v = v;
            edge.w = w;
            edges.pb(edge);
        }
        sort(edges.begin(), edges.end());

        parent = vector<int>(n + 1);
        init_dsu(n);

        // Minimum Spanning Tree
        int minCost = 0;
        for(Edge edge : edges){
            if(find_rep(edge.u) != find_rep(edge.v)){
                union_set(edge.u, edge.v);
                minCost += edge.w;
            }
        }

        reverse(edges.begin(), edges.end());

        parent = vector<int>(n + 1);
        init_dsu(n);

        //Maximum Spanning Tree
        int maxCost = 0;
        for(Edge edge : edges){
            if(find_rep(edge.u) != find_rep(edge.v)){
                union_set(edge.u, edge.v);
                maxCost += edge.w;
            }
        }
        int ans = minCost + maxCost;
        if(ans % 2 == 0){
            ans /= 2;
            cout << "Case " << tc << ": " << ans << '\n';
        } else{
            cout << "Case " << tc << ": " << ans << "/2\n";
        }
    }
    return 0;
}
