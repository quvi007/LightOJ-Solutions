#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define mp make_pair
#define pb push_back

typedef pair<int, int> pii;

int main(){
    int T;
    cin >> T;
    for(int tc = 1; tc <= T; ++tc){
        pii points[4];
        for(int i = 0; i < 3; ++i){
            cin >> points[i].ff >> points[i].ss;
        }
        points[3] = mp(points[0].ff + points[2].ff - points[1].ff, points[0].ss + points[2].ss - points[1].ss);
        int area = 0;
        for(int i = 0; i < 4; ++i)
            area += points[i].ff * points[(i + 1) % 4].ss - points[i].ss * points[(i + 1) % 4].ff;
        area /= 2;
        if(area < 0) area *= -1;
        cout << "Case " << tc << ": " << points[3].ff << ' ' << points[3].ss << ' ' << area << '\n';
    }
    return 0;
}
