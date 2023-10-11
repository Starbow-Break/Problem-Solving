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

ll dp[51], dp1[51];

ll solve(ll N, ll X) {
    if(X == dp[N]) return dp1[N];
    
    ll ret = 0;
    if(X > 0) { X--; }
    else return ret;
    
    ret += solve(N-1, min(X, dp[N-1]));
    X -= min(X, dp[N-1]);
    
    if(X > 0) { ret++; X--; }
    else return ret;
    
    ret += solve(N-1, min(X, dp[N-1]));
    X -= min(X, dp[N-1]);
    
    if(X > 0) { X--; }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    dp[0] = 1; dp1[0] = 1;
    for(int i = 1; i <= 50; i++) {
        dp[i] = 2*dp[i-1]+3;
        dp1[i] = 2*dp1[i-1]+1;
    }
    
    ll N, X; cin >> N >> X;
    cout << solve(N, X);
    
    return 0;
}