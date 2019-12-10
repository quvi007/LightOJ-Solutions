#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    for(int tc = 1; tc <= T; ++tc){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int m;
        cin >> m;
        cout << "Case " << tc << ":\n";
        for(int i = 0; i < m; ++i){
            int a, b;
            cin >> a >> b;
            if(a > x1 && a < x2 && b > y1 && b < y2)
                cout << "Yes\n";
            else cout << "No\n";
        }
    }
    return 0;
}
