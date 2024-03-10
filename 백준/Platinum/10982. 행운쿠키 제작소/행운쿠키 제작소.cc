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

const int INF = 1e9;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T; cin >> T;
    int dp[100'001];
    
    while(T--) {
        int N; cin >> N;
        vector<pii> cookie(N);
        
        int ta = 0;
        for(int i = 0; i < N; i++) {
            int a, b; cin >> a >> b;
            cookie[i] = {a, b};
            ta += a;
        }
        
        fill(dp, dp+ta+1, INF); dp[ta] = 0;
        
        vector<int> temp(ta+1);
        for(int i = 0; i < N; i++) {
            fill(temp.begin(), temp.end(), INF);
            
            for(int w = ta; w >= 0; w--) {
                temp[w] = min(temp[w], dp[w]+cookie[i].se);
                if(w-cookie[i].fi >= 0)
                    temp[w-cookie[i].fi] = min(temp[w-cookie[i].fi], dp[w]);
            }
            
            for(int w = 0; w <= ta; w++) {
                dp[w] = temp[w];
            }
        }
        
        int ans = INF;
        for(int w = 0; w <= ta; w++) {
            ans = min(ans, max(ta-w, dp[w]));
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}
