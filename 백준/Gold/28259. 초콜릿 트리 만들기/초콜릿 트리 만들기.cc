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

bool have[500] = {false, };
ll dp[61][500];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, H, k; cin >> N >> H >> k;
    repeat(k) {
        int v; cin >> v;
        have[v] = true;
    }
    
    for(int i = 0; i < N; i++) {
        dp[0][i] = !have[i];
    }
    
    for(int h = 1; h <= H; h++) {
        for(int r = 0; r < N; r++) {
            dp[h][r] = 9e18;
            for(int l = 0; l < N; l++) {
                dp[h][r] = min(dp[h][r], dp[h-1][l]+dp[h-1][(r+N-l)%N]+!have[r]);
            }
        }
    }
    
    ll ans = 9e18;
    for(int i = 0; i < N; i++) ans = min(ans, dp[H][i]);
    cout << ans;
    
    return 0;
}