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

int C[5001][5001] = {0, };
int dp[5001][5001] = {0, };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    for(int i = 0; i <= 5000; i++) {
        for(int j = 0; j <= i; j++) {
            if(j == 0 || j == i) C[i][j] = 1;
            else C[i][j] = (C[i-1][j]+C[i-1][j-1])%MOD;
        }
    }
    
    for(int k = 1; k <= 5000; k++) {
        for(int n = k; n <= 5000; n++) {
            if(k == 1) dp[n][k] = 1;
            else {
                dp[n][k] = (dp[n][k-1]+1LL*dp[k-1][k-1]*C[n][k-1])%MOD;
            }
        }
    }
    
    int T; cin >> T;
    while(T--) {
        int N, K; cin >> N >> K;
        
        ll ans = 1;
        if(K > 1) { 
            ans *= 1LL*C[N-1][K-1]*dp[K-1][K-1];
            ans %= MOD;
        }
        if(K < N) {
            ans *= 2LL*dp[N-K][N-K];
            ans %= MOD;
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}