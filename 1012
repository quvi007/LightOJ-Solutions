#include<bits/stdc++.h>
using namespace std;
 
typedef pair<int, int> pii;
 
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
 
map<pii, bool> visited;
 
int c, fx[] = {-1, 1, 0, 0}, fy[] = {0, 0, -1, 1};
void dfs(pii v, vector<vector<char>> grid){
    visited[v] = true;
    vector<pii> adj;
    for(int i = 0; i < 4; ++i){
        if(grid[v.ff + fx[i]][v.ss + fy[i]] == '#') continue;
        adj.pb(mp(v.ff + fx[i], v.ss + fy[i]));
    }
    for(pii u : adj){
        if(!visited[u]){
            ++c;
            dfs(u, grid);
        }
    }
}
int main(){
    int T;
    cin >> T;
    for(int tc = 1; tc <= T; ++tc){
        int w, h;
        pii src;
        c = 1;
        visited.clear();
        cin >> w >> h;
        vector<vector<char>> grid(h + 2, vector<char>(w + 2, '#'));
        for(int i = 1; i <= h; ++i){
            string str;
            cin >> str;
            for(int j = 1; j <= w; ++j){
                grid[i][j] = str[j - 1];
                if(grid[i][j] == '@') src = mp(i, j);
            }
        }
        dfs(src, grid);
        cout << "Case " << tc << ": " << c << '\n';
    }
    return 0;
}
