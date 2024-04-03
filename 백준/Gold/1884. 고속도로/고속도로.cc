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

struct edge {
    int d, l, t;
};

int dp[101][10'001];

vector<edge> edges[101];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int K, N, R; cin >> K >> N >> R;
    
    for(int i = 1; i <= N; i++) {
        fill(dp[i], dp[i]+10'001, 1e9);    
    }
    
    while(R--) {
        int s, d, l, t; cin >> s >> d >> l >> t;
        edges[s].pb({d, l, t});
    }
    
    dp[1][0] = 0;
    for(int len = 0; len <= 10000; len++) {
        for(int cur = 1; cur <= N; cur++) {
            for(auto &[next, l, t]: edges[cur]) {
                if(len+l > 10000) continue;
                dp[next][len+l] = min(dp[next][len+l], dp[cur][len]+t);
            }
        }
    }
    
    int ans = 1e9;
    for(int len = 0; len <= 10000; len++) {
        if(dp[N][len] <= K) {
            ans = len; break;
        }
    }
    
    cout << (ans == 1e9 ? -1 : ans);
    
    return 0;
}