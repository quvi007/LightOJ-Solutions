#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;
    double ab, bc, ac, r, ans;
    cin >> T;
    for(int tc = 1; tc <= T; ++tc){
        cin >> ab >> bc >> ac >> r;
        ans = sqrt((r) / (r + 1)) * ab;
        cout << fixed << setprecision(7) << "Case " << tc << ": " << ans << '\n';
    }
    return 0;
}
