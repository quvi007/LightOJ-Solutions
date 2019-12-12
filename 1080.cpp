#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;

struct node{
    int val, prop;
} t[MAXN * 4];

void build(int a[], int v, int tl, int tr){
    if(tl == tr){
        t[v].val = a[tl];
        t[v].prop = 0;
    } else{
        int tm = (tl + tr) / 2;
        build(a, v * 2, tl, tm);
        build(a, v * 2 + 1, tm + 1, tr);
        t[v].val = t[v * 2].val + t[v * 2 + 1].val;
        t[v].prop = 0;
    }
}

void update(int v, int tl, int tr, int l, int r, int new_val){
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

int query(int v, int tl, int tr, int l, int r, int carry = 0){
    if(l > r) return 0;
    if(tl == l && tr == r){
        return t[v].val + carry * (tr - tl + 1);
    } else{
        int r1, r2, tm = (tl + tr) / 2;
        r1 = query(v * 2, tl, tm, l, min(r, tm), carry + t[v].prop);
        r2 = query(v * 2 + 1, tm + 1, tr, max(tm + 1, l), r, carry + t[v].prop);
        return r1 + r2;
    }
}

int main(){
    int T;
    scanf("%d", &T);
    for(int tc = 1; tc <= T; ++tc){
        memset(t, 0, sizeof t);
        int n, q;
        char str[MAXN + 5], d_s[2];
        scanf("%s", str);
        n = strlen(str);
        scanf("%d", &q);
        int a[n + 1];
        for(int i = 1; i <= n; ++i){
            a[i] = str[i - 1] - '0';
        }
        build(a, 1, 1, n);
        printf("Case %d:\n", tc);
        for(int i = 0; i < q; ++i){
            scanf("%s", d_s);
            if(d_s[0] == 'I'){
                int i, j;
                scanf("%d %d", &i, &j);
                update(1, 1, n, i, j, 1);
            } else if(d_s[0] == 'Q'){
                int i;
                scanf("%d", &i);
                printf("%d\n", query(1, 1, n, i, i) % 2);
            }
        }
    }
    return 0;
}
