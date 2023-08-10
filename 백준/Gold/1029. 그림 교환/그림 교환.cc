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

int w[15][15];
int dp[1 << 15][15][10] = {0, };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    for(int r = 0; r < N; r++) {
        ll v; cin >> v;
        for(int c = N-1; c >= 0; c--) {
            w[r][c] = v%10;
            v /= 10;
        }
    }
    
    dp[1][0][0] = 1;
    
    for(int s = 0; s < 1<<N; s++) {
        for(int n = 0; n < N; n++) {
            for(int p = 0; p <= 9; p++) {
                if(dp[s][n][p] == 0) continue;
                for(int i = 0; i < N; i++) {
                    if(!(s & 1<<i) && w[n][i] >= p) {
                        dp[s|1<<i][i][w[n][i]] = max(dp[s|1<<i][i][w[n][i]], dp[s][n][p]+1);
                    }
                }
            }
        }
    }
    
    int ans = 0;
    for(int s = 0; s < 1<<N; s++) {
        for(int n = 0; n < N; n++) {
            for(int p = 0; p <= 9; p++) {
                ans = max(ans, dp[s][n][p]);
            }
        }
    }
    cout << ans;
    
    return 0;
}
