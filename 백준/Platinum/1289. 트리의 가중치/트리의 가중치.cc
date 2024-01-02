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

vector<pii> edges[100'001];
int dp1[100'001] = {0, }, dp2[100'001] = {0, };
bool visited[100'001] = {false, };

void dfs(int cur) {
    visited[cur] = true;
    
    vector<int> sum; sum.pb(0);
    for(auto &[next, w]: edges[cur]) {
        if(!visited[next]) {
            dfs(next);
            dp1[cur] += (1LL*dp1[next]*w+w)%MOD;
            dp1[cur] %= MOD;
            sum.pb((1LL*dp1[next]*w+w)%MOD);
            // cout << dp1[cur] << '\n';
        }
    }
    
    for(int i = 1; i < sum.size(); i++) {
        sum[i] = (sum[i]+sum[i-1])%MOD;
    }
    
    // for(auto &c: sum) cout << c << ' ';
    // cout << '\n';
    for(int i = 1; i < sum.size()-1; i++) {
        dp2[cur] += 1LL*(sum[i]-sum[i-1])*(sum[sum.size()-1]-sum[i])%MOD;
        dp2[cur] %= MOD;
    }
    
    dp2[cur] += dp1[cur]; dp2[cur] %= MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    for(int i = 1; i <= N-1; i++) {
        int a, b, w; cin >> a >> b >> w;
        edges[a].pb({b, w}); edges[b].pb({a, w});
    }
    
    dfs(1);
    
    // for(int i = 1; i <= N; i++) cout << dp1[i] << ' ';
    // cout << '\n';
    // for(int i = 1; i <= N; i++) cout << dp2[i] << ' ';
    // cout << '\n';
    int ans = 0;
    for(int i = 1; i <= N; i++) {
        ans += dp2[i]; ans %= MOD;
    }
    
    cout << ans;
    
    return 0;
}
