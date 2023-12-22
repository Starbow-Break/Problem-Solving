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

const ll INF = 1'000'000'000'000'000'000;

ll dp[301][301][2];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, M; cin >> N >> M;
    vector<int> x(N), left, right;
    int lcnt = 0, rcnt = 0;

    for(int i = 0; i < N; i++) cin >> x[i];
    
    sort(all(x));
    right.pb(0);
    for(int i = 0; i < N; i++) {
        if(x[i] >= 0) {
            right.pb(x[i]);
            rcnt++;
        }
        else {
            left.pb(-x[i]);
            lcnt++;
        }
    }
    left.pb(0);
    reverse(all(left));
    
    // for(auto &v: left) cout << v << ' ';
    // cout << '\n';
    // for(auto &v: right) cout << v << ' ';
    // cout << '\n';
    
    ll ans = 0;
    
    for(int candy = 1; candy <= N; candy++) {
        for(int i = 0; i <= 300; i++) {
            for(int j = 0; j <= 300; j++) {
                dp[i][j][0] = dp[i][j][1] = INF;
            }
        }
        
        dp[0][0][0] = 0;
        dp[0][0][1] = 0;
        for(int s = 0; s < candy; s++) {
            for(int l = 0; l <= min(s, lcnt); l++) {
                // 왼쪽
                if(l < lcnt && s-l <= rcnt) {
                    dp[l+1][s-l][0] = min(dp[l+1][s-l][0], dp[l][s-l][0]+(candy-s)*(left[l+1]-left[l]));
                    dp[l+1][s-l][0] = min(dp[l+1][s-l][0], dp[l][s-l][1]+(candy-s)*(left[l+1]+right[s-l]));
                }
                // 오른쪽
                if(l <= lcnt && s-l < rcnt) {
                    dp[l][s-l+1][1] = min(dp[l][s-l+1][1], dp[l][s-l][0]+(candy-s)*(right[s-l+1]+left[l]));
                    dp[l][s-l+1][1] = min(dp[l][s-l+1][1], dp[l][s-l][1]+(candy-s)*(right[s-l+1]-right[s-l]));
                }
            }
        }
        
        for(int l = 0; l <= min(candy, lcnt); l++) {
            if(0 <= candy-l && candy-l <= rcnt) {
                ans = max(ans, 1LL*M*candy-dp[l][candy-l][0]);
                ans = max(ans, 1LL*M*candy-dp[l][candy-l][1]);
            }
        }
    }
    
    cout << ans;
    
    return 0;
}