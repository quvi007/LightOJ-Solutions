#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5;
typedef long long ll;
struct node{
    ll val, prop;
};
node t[4 * MAXN];
void build(ll a[], int v, int tl, int tr){
    if(tl == tr){
        t[v].val = a[tl];
        t[v].prop = 0;
    } else{
        int tm = (tl + tr) / 2;
        build(a, v * 2, tl, tm);
        build(a, v * 2 + 1, tm + 1, tr);
        t[v].val = t[v * 2].val + t[v * 2 + 1].val;
    }
}

void update(int v, int tl, int tr, int l, int r, ll new_val){
    if(l > r) return;
    if(tl == l && tr == r){
        t[v].val += (tr - tl + 1) * new_val;
        t[v].prop += new_val;
    } else{
        int tm = (tl + tr) / 2;
        update(v * 2, tl, tm, l, min(r, tm), new_val);
        update(v * 2 + 1, tm + 1, tr, max(tm + 1, l), r, new_val);
        t[v].val = t[v * 2].val + t[v * 2 + 1].val + (tr - tl + 1) * t[v].prop;
    }
}

ll query(int v, int tl, int tr, int l, int r, ll carry = 0){
    if(l > r) return 0;
    if(tl == l && tr == r){
        return t[v].val + carry * (tr - tl + 1);
    } else{
        int tm = (tl + tr) / 2;
        ll r1, r2;
        r1 = query(v * 2, tl, tm, l, min(r, tm), carry + t[v].prop);
        r2 = query(v * 2 + 1, tm + 1, tr, max(tm + 1, l), r, carry + t[v].prop);
        return r1 + r2;
    }
}

int main(){
    int T;
    scanf("%d", &T);
    for(int tc = 1; tc <= T; ++tc){
        memset(t, 0 ,sizeof t);
        int n, q;
        scanf("%d %d", &n, &q);
        ll a[n];
        memset(a, 0, sizeof a);
        build(a, 1, 0, n - 1);
        printf("Case %d:\n", tc);
        for(int i = 0; i < q; ++i){
            int cmd;
            scanf("%d", &cmd);
            if(cmd == 0){
                int x, y;
                ll v;
                scanf("%d %d %lld", &x, &y, &v);
                update(1, 0, n - 1, x, y, v);
            } else if(cmd == 1){
                int x, y;
                scanf("%d %d", &x, &y);
                printf("%lld\n", query(1, 0, n - 1, x, y));
            }
        }
    }
    return 0;
}
