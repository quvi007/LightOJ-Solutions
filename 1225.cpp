#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    for(int tc = 1; tc <= T; ++tc){
        string n, t;
        cin >> n;
        t = n;
        reverse(n.begin(), n.end());
        if(n == t) cout << "Case " << tc << ": Yes\n";
        else cout << "Case " << tc << ": No\n";
    }
    return 0;
}
