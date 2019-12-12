#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;
    double a, b, c, d, k, theta2, ans;
    cin >> T;
    for(int tc = 1; tc <= T; ++tc){
        cin >> a >> b >> c >> d;
        k = c - a;
        theta2 = acos((d * d - b * b - k * k) / (2 * k * b));
        ans = 0.5 * (a + c) * b * sin(theta2);
        cout << fixed << setprecision(7) << "Case " << tc << ": " << ans << '\n';
    }
    return 0;
}
