#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1000;
int checked[MAXN + 5];
#define pb push_back
vector<int> primes, adj[MAXN + 5];
void sieve(){
    int x = 1;
    for(int i = 2; i <= MAXN; ++i){
        if(!checked[i]){
            for(int j = i * i; j <= MAXN; j += i){
                checked[j] = 1;
            }
            x = i;
            primes.pb(i);
        }
    }
}

int visited[2 * MAXN], d[2 * MAXN];

int bfs(int s, int t){
    queue<int> q;
    memset(visited, 0, sizeof visited);
    d[s] = 0;
    visited[s] = 1;
    q.push(s);
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int u : adj[v]){
            if(!visited[u + v]){
                visited[u + v] = 1;
                d[u + v] = d[v] + 1;
                if((u + v) > t) continue;
                q.push(u + v);
                if(u + v == t){
                    return d[u + v];
                }
            }
        }
    }
    return -1;
}

int main(){
    sieve();
    for(int i = 1; i <= 1000; ++i) {
        for (int j = 0; j < primes.size(); ++j) {
            if (primes[j] >= i) break;
            if (i % primes[j] == 0) {
                adj[i].pb(primes[j]);
            }
        }
    }
    int T;
    scanf("%d", &T);
    for(int tc = 1; tc <= T; ++tc){
        int s, t;
        scanf("%d %d", &s, &t);
        if(s == t) {
            cout << "Case " << tc << ": 0\n";
            continue;
        }
        cout << "Case " << tc << ": " << bfs(min(s, t), max(s, t)) << '\n';
    }
    return 0;
}
