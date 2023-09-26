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

int dp[1001][1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, m; cin >> n >> m;
    vector<int> words;
    repeat(n) {
        int v; cin >> v;
        words.pb(v);
    }
    
    for(int i = 0; i <= n; i++) fill(dp[i], dp[i]+m+1, 2e9);
    dp[0][m] = 0;
    
    for(int i = 0; i < n; i++) {
        for(int j = m; j >= 0; j--) {
            if(dp[i][j] != 2e9) {
                if(j == m) {
                    dp[i+1][j-words[i]] = min(dp[i][j], dp[i+1][j-words[i]]);
                }
                else {
                    if(j > words[i]) {
                        dp[i+1][j-words[i]-1] = min(dp[i][j], dp[i+1][j-words[i]-1]);
                    }
                    dp[i+1][m-words[i]] = min(dp[i][j]+j*j, dp[i+1][m-words[i]]);
                }
            }
        }
    }
    
    int ans = 2e9;
    for(int j = m; j >= 0; j--) {
        ans = min(ans, dp[n][j]);
    }
    cout << ans;
    
    
    return 0;
}