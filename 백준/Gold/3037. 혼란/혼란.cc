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
int dp[1001][10001] = {0, };
int sum[1001][10001] = {0, };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    for(int n = 1; n <= 1000; n++) {
        dp[n][0] = 1; sum[n][0] = 1;
    }
    for(int c = 0; c <= 10000; c++) sum[1][c] = 1;
    
    for(int n = 2; n <= 1000; n++) {
        for(int c = 1; c <= 10000; c++) {
            if(c >= n) {
                dp[n][c] = (sum[n-1][c]+MOD-sum[n-1][c-n])%MOD;
            }
            else {
                dp[n][c] = sum[n-1][c];
            }
            sum[n][c] = (sum[n][c-1]+dp[n][c])%MOD;
        }
    }
    
    int N, C; cin >> N >> C;
    cout << dp[N][C];
    
    return 0;
}