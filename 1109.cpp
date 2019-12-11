#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

int divCount(int n){
    int c = 0;
    for(int i = 1; i * i <= n; ++i){
        if(n % i == 0) c += 2;
        if((i * i) == n) c -= 1;
    }
    return c;
}

int main(){
    vector<pii> a;
    for(int i = 1; i <= 1000; ++i) {
        pii p = mp(divCount(i), -i);
        a.pb(p);
    }
    sort(a.begin(), a.end());
    int T;
    cin >> T;
    for(int tc = 1; tc <= T; ++tc){
        int n;
        cin >> n;
        cout << "Case " << tc << ": " << -a[n - 1].ss << '\n';
    }
    return 0;
}
