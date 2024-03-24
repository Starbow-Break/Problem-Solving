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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    vector<pii> pts(N);
    
    for(int i = 0; i < N; i++) {
        int x, y; cin >> x >> y;
        pts[i] = {x, y};
    }
    
    ll ans = 9e18;
    for(int i = 0; i < N; i++) {
        for(int j = i+1; j < N; j++) {
            int x1 = 1e9+1, x2 = -1e9-1;
            int y1 = 1e9+1, y2 = -1e9-1;
            for(int k = 0; k < N; k++) {
                if(i != k && j != k) {
                    x1 = min(x1, pts[k].fi);
                    x2 = max(x2, pts[k].fi);
                    y1 = min(y1, pts[k].se);
                    y2 = max(y2, pts[k].se);
                }
            }
            
            int len = max(x2-x1+2, y2-y1+2);
            ans = min(ans, 1LL*len*len);
        }
    }
    
    cout << ans;
    
    return 0;
}