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
    
    int H, W, N; cin >> H >> W >> N;
    
    vector<pii> sticker(N);
    for(int i = 0; i < N; i++) {
        int R, C; cin >> R >> C;
        sticker[i] = {R, C};
    }
    
    int ans = 0;
    for(int i = 0; i < N; i++) {
        for(int j = i+1; j < N; j++) {
            if(max(sticker[i].fi, sticker[j].fi) <= H && sticker[i].se+sticker[j].se <= W) {
                ans = max(ans, sticker[i].fi*sticker[i].se+sticker[j].fi*sticker[j].se);
            }
            if(max(sticker[i].se, sticker[j].se) <= H && sticker[i].fi+sticker[j].fi <= W) {
                ans = max(ans, sticker[i].fi*sticker[i].se+sticker[j].fi*sticker[j].se);
            }
            if(max(sticker[i].fi, sticker[j].se) <= H && sticker[i].se+sticker[j].fi <= W) {
                ans = max(ans, sticker[i].fi*sticker[i].se+sticker[j].fi*sticker[j].se);
            }
            if(max(sticker[i].se, sticker[j].fi) <= H && sticker[i].fi+sticker[j].se <= W) {
                ans = max(ans, sticker[i].fi*sticker[i].se+sticker[j].fi*sticker[j].se);
            }
            if(max(sticker[i].fi, sticker[j].fi) <= W && sticker[i].se+sticker[j].se <= H) {
                ans = max(ans, sticker[i].fi*sticker[i].se+sticker[j].fi*sticker[j].se);
            }
            if(max(sticker[i].se, sticker[j].se) <= W && sticker[i].fi+sticker[j].fi <= H) {
                ans = max(ans, sticker[i].fi*sticker[i].se+sticker[j].fi*sticker[j].se);
            }
            if(max(sticker[i].fi, sticker[j].se) <= W && sticker[i].se+sticker[j].fi <= H) {
                ans = max(ans, sticker[i].fi*sticker[i].se+sticker[j].fi*sticker[j].se);
            }
            if(max(sticker[i].se, sticker[j].fi) <= W && sticker[i].fi+sticker[j].se <= H) {
                ans = max(ans, sticker[i].fi*sticker[i].se+sticker[j].fi*sticker[j].se);
            }
        }
    }
    
    cout << ans;
    
    return 0;
}
