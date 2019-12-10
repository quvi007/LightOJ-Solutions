#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    for(int tc = 1; tc <= T; ++tc){
        int a[3];
        for(int i = 0; i < 3; ++i)
            cin >> a[i];
        sort(a, a + 3);
        if((a[0] * a[0] + a[1] * a[1]) == a[2] * a[2])
            cout << "Case " << tc << ": yes\n";
        else cout << "Case " << tc << ": no\n";
    }
    return 0;
}
