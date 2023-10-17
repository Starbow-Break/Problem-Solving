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

ll dp[4000][2000] = {0, };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int d, m; cin >> d >> m;
    dp[1][1] = 1;
    for(int i = 1; i < d-1; i++) {
        for(int j = 1; j <= min(i, d-i); j++) {
            if(j+1 <= 2000) {
                dp[i+1][j+1] += dp[i][j];
                dp[i+1][j+1] %= m;
            }
            if(j-1 > 0) {
                dp[i+1][j-1] += dp[i][j];
                dp[i+1][j-1] %= m;
            }
        }
    }
    
    cout << dp[d-1][1];
    
    return 0;
}