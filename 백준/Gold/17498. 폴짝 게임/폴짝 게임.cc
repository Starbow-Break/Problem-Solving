#include <bits/stdc++.h>
#define fi first
#define se second
#define repeat(n) for(int i = 0; i < n; i++)
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define push_back pb
#define all(vec) vec.begin(), vec.end()
#define rall(vec) vec.rbegin(), vec.rend()
#define compress(vec) sort(all(vec)); vec.erase(unique(all(vec)), vec.end());

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;
using int128 = __int128_t;

const int INF = 2e9;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M, D; cin >> N >> M >> D;
    int dp[200000], arr[200000];
    fill(dp, dp+200000, -INF);
    for(int i = 0; i < N*M; i++) cin >> arr[i];
    
    for(int r = 0; r < N; r++) {
        for(int c = 0; c < M; c++) {
            if(r == 0) dp[r*M+c] = 0;
            else {
                for(int d = D; d >= 1; d--) {
                    if(r-d < 0) continue;
                    for(int cc = c-(D-d); cc <= c+(D-d); cc++) {
                        if(cc < 0 || cc >= M) continue;
                        dp[r*M+c] = max(dp[r*M+c], dp[M*(r-d)+cc]+arr[(r-d)*M+cc]*arr[r*M+c]);
                    }
                }
            }
        }
    }
    
    int ans = -INF;
    for(int c = 0; c < M; c++) {
        ans = max(ans, dp[M*(N-1)+c]);
    }
    cout << ans;
    
    return 0;
}
