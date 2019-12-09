#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
const int INF = 1e9 + 5;
int fx[] = {-1, 1, 0, 0}, fy[] = {0, 0, -1, 1};
int bfs(pii s, pii e, vector<vector<char>> grid){
    queue<pii> q;
    map<pii, bool> visited;
    map<pii, int> d;
    d[s] = 0;
    visited[s] = true;
    q.push(s);
    while(!q.empty()){
        pii v = q.front();
        q.pop();
        if(v == e) break;
        vector<pii> adj;
        for(int i = 0; i < 4; ++i){
            char ch = grid[v.ff + fx[i]][v.ss + fy[i]];
            if(ch == grid[e.ff][e.ss] || (ch >= 'A' && ch <= 'Z' && ch < grid[s.ff][s.ss]) || ch == '.') adj.pb(mp(v.ff + fx[i], v.ss + fy[i]));
        }
        for(pii u : adj){
            if(!visited[u]){
                visited[u] = true;
                d[u] = d[v] + 1;
                q.push(u);
            }
        }
    }
    return ((d[e] == 0) ? INF : d[e]);
}
int main(){
    int T;
    cin >> T;
    for(int tc = 1; tc <= T; ++tc){
        int n;
        cin >> n;
        vector<vector<char>> grid(n + 2, vector<char>(n + 2, '#'));
        char nax = 'A' - 1;
        map<char, pii> locs;
        for(int i = 1; i <= n; ++i){
            string str;
            cin >> str;
            for(int j = 1; j <= n; ++j){
                grid[i][j] = str[j - 1];
                if(str[j - 1] >= 'A' && str[j - 1] <= 'Z') {
                    locs[str[j - 1]] = mp(i, j);
                    nax = max(nax, str[j - 1]);
                }
            }
        }
        int ans = 0, c = 1;
        for(char ch = 'A'; ch < nax; ++ch){
            int x = bfs(locs[ch], locs[ch + 1], grid);
            if(x == INF) {
                c = 0;
                break;
            }
            ans += x;
        }
        if(c) cout << "Case " << tc << ": " << ans << '\n';
        else cout << "Case " << tc << ": Impossible\n";
    }
    return 0;
}
