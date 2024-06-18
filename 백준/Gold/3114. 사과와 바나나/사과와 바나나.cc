#include <bits/stdc++.h>
#define fi first
#define se second
#define repeat(n) for(int i = 0; i < n; i++)
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORIter(v, vec) for(auto &v, vec)
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

int dp[1501][1501] = {0, };
int w[2][1501][1501] = {0, };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int R, C; cin >> R >> C;
    FOR(r, 1, R+1) {
        FOR(c, 1, C+1) {
            string s; cin >> s;
            int value = 0;
            FOR(i, 1, s.length()) {
                value = 10 * value + (s[i] - '0');
            }
            
            w[s[0] - 'A'][r][c] = value;
        }
    }
    
    FOR(c, 1, C+1) {
        FOR(r, 1, R+1) {
            w[0][r][c] += w[0][r-1][c];
            w[1][r][c] += w[1][r-1][c];
        }
    }
    
    FOR(r, 1, R+1) dp[r][0] = -1e9;
    FOR(c, 1, C+1) dp[0][c] = -1e9;
    
    FOR(c, 1, C+1) {
        FOR(r, 1, R+1) {
            // 오른쪽
            dp[r][c] = max(dp[r][c-1] + w[1][r-1][c] + (w[0][R][c] - w[0][r][c]), dp[r][c]);
            // 아래
            dp[r][c] = max(dp[r-1][c] - (w[0][r][c] - w[0][r-1][c]), dp[r][c]);
            // 대각선
            dp[r][c] = max(dp[r-1][c-1] + w[1][r-1][c] + (w[0][R][c] - w[0][r][c]), dp[r][c]);
        }
    }
    
    cout << dp[R][C];
    
    return 0;
}
