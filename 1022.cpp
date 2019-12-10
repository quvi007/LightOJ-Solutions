#include<bits/stdc++.h>
using namespace std;
const double pi  = acos(-1);
int main(){
    int T;
    cin >> T;
    for(int tc = 1; tc <= T; ++tc){
        double r;
        cin >> r;
        double ans = 4 * r * r - pi * r * r + 1e-9;
        cout << fixed << setprecision(2) << "Case " << tc << ": " << ans << '\n';
    }
}
