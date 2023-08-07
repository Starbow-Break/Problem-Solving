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

ll dp[2000][2000] = {0, };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    vector<int> cake;
    repeat(N) {
        int v; cin >> v;
        cake.pb(v);
    }
    
    if(N == 1) {
        cout << cake[0];
        return 0;
    }
    
    for(int i = 0; i < N; i++) {
        dp[(i+N-1)%N][(i+1)%N] = cake[i];
    }
    
    for(int i = 2; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(i&1) {
                dp[(j+N-1)%N][(j+i)%N] = max(dp[(j+N-1)%N][(j+i)%N], dp[j][(j+i)%N]+cake[j]);
                dp[j][(j+i+1)%N] = max(dp[j][(j+i+1)%N], dp[j][(j+i)%N]+cake[(j+i)%N]);
            }
            else {
                if(cake[j] > cake[(j+i)%N]) {
                    dp[(j+N-1)%N][(j+i)%N] = max(dp[(j+N-1)%N][(j+i)%N], dp[j][(j+i)%N]);
                }
                else {
                    dp[j][(j+i+1)%N] = max(dp[j][(j+i+1)%N], dp[j][(j+i)%N]);
                }
            }
        }
    }
    
    ll ans = 0;
    if(N&1) {
        for(int i = 0; i < N; i++) {
            ans = max(ans, dp[i][i]+cake[i]);
        }
    }
    else {
        for(int i = 0; i < N; i++) {
            ans = max(ans, dp[i][i]);
        }
    }
    
    cout << ans;
    
    return 0;
}
