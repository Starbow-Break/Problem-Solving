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

const int MOD = 1'000'000'007;

ll dp[100'001][8] = {0, };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    dp[1][0] = 1;
    dp[1][3] = 1;
    dp[1][6] = 1;
    dp[0][7] = 1;
    
    for(int n = 2; n <= 100'000; n++) {
        dp[n][0] = dp[n-1][7];
        dp[n][1] = dp[n-1][6];
        dp[n][2] = dp[n-1][5];
        dp[n][3] = (dp[n-1][4]+dp[n][0])%MOD;
        dp[n][4] = dp[n-1][3];
        dp[n][5] = dp[n-1][2];
        dp[n][6] = (dp[n-1][1]+dp[n][0])%MOD;
        dp[n][7] = (dp[n-1][0]+dp[n][1]+dp[n][4])%MOD;
    }
    
    int T; cin >> T;
    while(T--) {
        ll ans = 0;
        int N, R, C; cin >> N >> R >> C;
        if(R == 1) {
            ans += (dp[C-1][4]*dp[N-C][7])%MOD;
            ans += (dp[C-1][5]*dp[N-C][6])%MOD;
            ans += (dp[C-1][6]*dp[N-C][5])%MOD;
            ans += (dp[C-1][7]*dp[N-C][4])%MOD;
            ans += (dp[C-1][7]*dp[N-C][7])%MOD;
            ans %= MOD;
        }
        else if(R == 2) {
            ans += (dp[C-1][2]*dp[N-C][7])%MOD;
            ans += (dp[C-1][6]*dp[N-C][3])%MOD;
            ans += (dp[C-1][3]*dp[N-C][6])%MOD;
            ans += (dp[C-1][7]*dp[N-C][2])%MOD;
            ans %= MOD;
        }
        else {
            ans += (dp[C-1][1]*dp[N-C][7])%MOD;
            ans += (dp[C-1][3]*dp[N-C][5])%MOD;
            ans += (dp[C-1][5]*dp[N-C][3])%MOD;
            ans += (dp[C-1][7]*dp[N-C][1])%MOD;
            ans += (dp[C-1][7]*dp[N-C][7])%MOD;
            ans %= MOD;
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}
