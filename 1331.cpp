#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;
    double r1, r2, r3, a, b, c, a_a, a_t, A, B, C;
    cin >> T;
    for(int tc = 1; tc <= T; ++tc){
        cin >> r1 >> r2 >> r3;
        a = r1 + r2;
        b = r2 + r3;
        c = r3 + r1;
        C = acos((a * a + b * b - c * c) / (2 * a * b));
        B = acos((c * c + a * a - b * b) / (2 * c * a));
        A = acos((b * b + c * c - a * a) / (2 * b * c));
        a_t = 0.5 * a * b * sin(C);
        a_a = (r2 * r2 * C + r3 * r3 * A + r1 * r1 * B) * 0.5;
        cout << fixed << setprecision(7) << "Case " << tc << ": " << (a_t - a_a) << '\n';
    }
    return 0;
}
