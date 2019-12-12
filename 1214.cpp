#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll strToLong(string str){
    ll ans = 0;
    if(str == "") return ans;
    for(int i = 0; i < str.length(); ++i)
        ans = ans * 10 + str[i] - '0';
    return ans;
}

string longToStr(ll n){
    string ans = "";
    if(n == 0) return ans;
    while(n){
        char d = n % 10;
        n /= 10;
        ans += d + '0';
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

ll bigMod(string str, ll b){
    ll dividend = 0LL;
    for(int i = 0; i < str.length(); i += 9){
        dividend = strToLong(longToStr(dividend) + str.substr(i, ((i + 9) >= str.length()) ? (str.length() - i) : 9));
        dividend = dividend % b;
    }
    return dividend;
}

bool divisible(string str, int b){
    int ans = bigMod(str, b);
    return ans == 0;
}

int main(){
    int T;
    cin >> T;
    for(int tc = 1; tc <= T; ++tc){
        string str;
        ll b;
        cin >> str >> b;
        if(b < 0) b *= -1;
        if(str[0] == '+' || str[0] == '-') str = str.substr(1);
        if(divisible(str, b)) cout << "Case " << tc << ": divisible\n";
        else cout << "Case " << tc << ": not divisible\n";
    }
    return 0;
}
