#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

#define ff first
#define ss second
#define pb push_back
#define mp make_pair

int fx[] = {-1, 1, 0, 0}, fy[] = {0, 0, -1, 1};

int main(){
    int T;
    cin >> T;
    for(int tc = 1; tc <= T; ++tc){
        int m, n;
        cin >> m >> n;
        vector<vector<char>> grid(m + 2, vector<char>(n + 2, '#'));
        vector<pii> srcs;
        pii dest;
        for(int i = 1; i <= m; ++i){
            string str;
            cin >> str;
            for(int j = 1; j <= n; ++j){
                grid[i][j] = str[j - 1];
                if(str[j - 1] >= 'a' && str[j - 1] <= 'c'){
                    srcs.pb(mp(i, j));
                } else if(str[j - 1] == 'h') dest = mp(i, j);
            }
        }
        int ans = -1;
        for(pii src : srcs){
            queue<pii> q;
            map<pii, bool> visited;
            map<pii, int> d;
            d[src] = 0;
            visited[src] = true;
            q.push(src);
            while(!q.empty()){
                pii v = q.front();
                q.pop();
                vector<pii> adj;
                for(int i = 0; i < 4; ++i){
                    char ch = grid[v.ff + fx[i]][v.ss + fy[i]];
                    if(ch != '#') adj.pb(mp(v.ff + fx[i], v.ss + fy[i]));
                }
                for(pii u : adj){
                    if(!visited[u]){
                        q.push(u);
                        d[u] = d[v] + 1;
                        visited[u] = true;
                    }
                }
            }
            ans = max(ans, d[dest]);
        }
        cout << "Case " << tc << ": " << ans << '\n';
    }
    return 0;
}
