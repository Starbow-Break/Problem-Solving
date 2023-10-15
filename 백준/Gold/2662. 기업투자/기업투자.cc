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

int arr[301][21];
int dp[21][301] = {0, };
int bef[21][301] = {0, };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M; cin >> N >> M;
    repeat(N) {
        int v; cin >> v;
        for(int j = 1; j <= M; j++) cin >> arr[v][j];
    }
    
    for(int n = 1; n <= N; n++) {
        dp[1][n] = arr[n][1];
    }
    
    for(int m = 1; m < M; m++) {
        for(int n = 0; n <= N; n++) {
            for(int d = 0; d <= N-n; d++) {
                if(dp[m+1][n+d] < dp[m][n]+arr[d][m+1]) {
                    dp[m+1][n+d] = dp[m][n]+arr[d][m+1];
                    bef[m+1][n+d] = n;
                }
            }
        }
    }
    
    cout << dp[M][N] << '\n';
    
    vector<int> ans;
    for(int m = M, n = N; m >= 1; m--) {
        ans.pb(n-bef[m][n]);
        n = bef[m][n];
    }
    
    reverse(all(ans));
    
    for(auto &a: ans) cout << a << ' ';
    
    return 0;
}
