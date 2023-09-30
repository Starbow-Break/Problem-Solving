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
const int OFFSET = 2;

int dp[101][10][5] = {0, };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    for(int i = 0; i <= 9; i++) dp[1][i][OFFSET] = 1;
    
    for(int n = 1; n < N; n++) {
        for(int i = 0; i <= 9; i++) {
            for(int k = -2; k <= 2; k++) {
                if(i < 9 && k < 2) {
                    dp[n+1][i+1][max(OFFSET+1, OFFSET+k+1)] += dp[n][i][OFFSET+k];
                    dp[n+1][i+1][max(OFFSET+1, OFFSET+k+1)] %= MOD;
                }
                if(i > 0 && k > -2) {
                    dp[n+1][i-1][min(OFFSET-1, OFFSET+k-1)] += dp[n][i][OFFSET+k];
                    dp[n+1][i-1][min(OFFSET-1, OFFSET+k-1)] %= MOD;
                }
            }
        }
    }
    
    int ans = 0;
    for(int i = 0; i <= 9; i++) {
        for(int k = -2; k <= 2; k++) {
            ans += dp[N][i][OFFSET+k];
            ans %= MOD;
        }
    }
    
    cout << ans;
    
    return 0;
}
