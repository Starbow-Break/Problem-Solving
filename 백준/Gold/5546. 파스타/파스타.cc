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

const int MOD = 10'000;

int plan[101] = {0, };
int dp[101][4][3] = {0, };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, K; cin >> N >> K;
    while(K--) {
        int v, i; cin >> v >> i;
        plan[v] = i;
    }
    
    dp[1][1][1] = (plan[1] == 0 || plan[1] == 1);
    dp[1][2][1] = (plan[1] == 0 || plan[1] == 2);
    dp[1][3][1] = (plan[1] == 0 || plan[1] == 3);
    
    for(int n = 1; n < N; n++) {
        for(int k = 1; k <= 3; k++) {
            for(int c = 1; c < 3; c++) {
                if(plan[n+1] == 0 || plan[n+1] == 1) {
                    if(k == 1 && c+1 < 3) {
                        dp[n+1][1][c+1] += dp[n][k][c];
                        dp[n+1][1][c+1] %= MOD;
                    }
                    else if(k != 1) {
                        dp[n+1][1][1] += dp[n][k][c];
                        dp[n+1][1][1] %= MOD;
                    }
                }
                
                if(plan[n+1] == 0 || plan[n+1] == 2) {
                    if(k == 2 && c+1 < 3) {
                        dp[n+1][2][c+1] += dp[n][k][c];
                        dp[n+1][2][c+1] %= MOD;
                    }
                    else if(k != 2) {
                        dp[n+1][2][1] += dp[n][k][c];
                        dp[n+1][2][1] %= MOD;
                    }
                }
                
                if(plan[n+1] == 0 || plan[n+1] == 3) {
                    if(k == 3 && c+1 < 3) {
                        dp[n+1][3][c+1] += dp[n][k][c];
                        dp[n+1][3][c+1] %= MOD;
                    }
                    else if(k != 3) {
                        dp[n+1][3][1] += dp[n][k][c];
                        dp[n+1][3][1] %= MOD;
                    }
                }
            }
        }
    }
    
    int ans = 0;
    for(int k = 1; k <= 3; k++) {
        for(int c = 1; c < 3; c++) {
            ans += dp[N][k][c];
            ans %= MOD;
        }
    }
    
    cout << ans;
    
    
    return 0;
}
