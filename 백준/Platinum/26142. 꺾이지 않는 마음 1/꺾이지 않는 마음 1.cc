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

vector<pll> dragon;
ll dp[10001][10001] = {0, };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    for(int i = 1; i <= N; i++) {
        ll d, h; cin >> d >> h;
        dragon.pb({d, h});
    }
    
    sort(all(dragon));
    
    for(int i = 1; i <= N; i++) {
        for(int j = i; j <= N; j++) {
            dp[i][j] = max(dp[i][j-1], dp[i-1][j-1]+dragon[j-1].fi*(i-1)+dragon[j-1].se);
        }
        
        cout << dp[i][N] << '\n';
    }
    
    return 0;
}
