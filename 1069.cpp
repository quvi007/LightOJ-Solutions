#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    for(int tc = 1; tc <= T; ++tc){
        int u, v;
        cin >> u >> v;
        int d = u - v;
        if(d < 0) d *= -1;
        int ans = 19 + (d + u) * 4;
        cout << "Case " << tc << ": " << ans  << '\n';
    }
    return 0;
}
