#include <bits/stdc++.h>
#define fi first
#define se second
#define repeat(n) for(int i = 0; i < n; i++)
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define pb push_back 
#define all(vec) vec.begin(), vec.end()
#define rall(vec) vec.rbegin(), vec.rend()
#define compress(vec) sort(all(vec)); vec.erase(unique(all(vec)), vec.end());

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;
using int128 = __int128_t;

ll dp[41] = {0, };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string s; cin >> s;
    dp[0] = 1;
    for(int i = 1; i <= s.length(); i++) {
        if(s[i-1] != '0') dp[i] += dp[i-1];
        if(i >= 2 && 10 <= (s[i-2]-'0')*10+(s[i-1]-'0') && (s[i-2]-'0')*10+(s[i-1]-'0') <= 34) {
            dp[i] += dp[i-2];
        }
    }
    
    cout << dp[s.length()];
    
    return 0;
}