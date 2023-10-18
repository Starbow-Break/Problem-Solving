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
int dp[10001][16][16] = {0, };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    dp[0][0][0] = 1;
    dp[0][7][0] = 1;
    dp[0][14][0] = 1;
    dp[0][7][7] = 1;
    dp[0][14][14] = 1;
    
    for(int n = 1; n <= 10000; n++) {
        for(int a = 0; a < 16; a++) {
            for(int b = 0; b < 16; b++) {
                if((a & b) == b) {
                    if(b == 0) {
                        dp[n][a][b] = dp[n-1][15][a];
                    }
                    else {
                        if((b & 7) == 7) {
                            dp[n][a][b] += dp[n][a][b-7];
                            dp[n][a][b] %= MOD;
                        }
                        if((b & 14) == 14) {
                            dp[n][a][b] += dp[n][a][b-14];
                            dp[n][a][b] %= MOD;
                        }
                        if(n-1 >= 0) dp[n][a][b] += dp[n-1][15-b][a-b];
                        dp[n][a][b] %= MOD;
                    }
                }
            }
        }
    }
    
    int T; cin >> T;
    while(T--) {
        int N; cin >> N;
        cout << dp[N][0][0] << '\n';
    }
    
    return 0;
}