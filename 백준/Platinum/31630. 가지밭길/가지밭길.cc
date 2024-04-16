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

int R, C, K;
int dp[5001][5001] = {0, };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> R >> C >> K;
    while(K--) {
        int r, c; cin >> r >> c;
        dp[r][c] = -1;
    }
    
    for(int r = 0; r <= R; r++) {
        if(dp[r][0] == -1) break;
        dp[r][0] = 1;
    }
    
    for(int c = 1; c <= C; c++) {
        int cur = 0; bool flag = true;
        for(int r = 0; r <= R; r++) {
            if(dp[r][c] == -1) {
                cur = 0; flag = true;
                continue;
            }
            
            if(dp[r][c-1] == -1) {
                flag = true;
            }
            else {
                if(flag) {
                    cur += dp[r][c-1];
                }
                else {
                    cur += (dp[r][c-1]+MOD-dp[r-1][c-1])%MOD;
                }
                flag = false;
            }
            
            cur %= MOD;
            dp[r][c] = cur;
        }
    }
    
    cout << dp[R][C];
    
    return 0;
}
