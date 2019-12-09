#include<bits/stdc++.h>
using namespace std;
int cTB(int a){
    int ans = 0, j = 1;
    while(a){
        ans += j * (a % 2);
        a /= 2;
        j *= 10;
    }
    return ans;
}
int main(){
    int T;
    cin >> T;
    for(int tc = 1; tc <= T; ++tc){
        int a, b, c, d, a1, b1, c1, d1;
        scanf("%d.%d.%d.%d", &a, &b, &c, &d);
        scanf("%d.%d.%d.%d", &a1, &b1, &c1, &d1);
        if(a > 255) swap(a, a1), swap(b, b1), swap(c, c1), swap(d, d1);
        if(cTB(a) == a1 && cTB(b) == b1 && cTB(c) == c1 && cTB(d) == d1)
            cout << "Case " << tc << ": Yes\n";
        else cout << "Case " << tc << ": No\n";
    }
    return 0;
}
