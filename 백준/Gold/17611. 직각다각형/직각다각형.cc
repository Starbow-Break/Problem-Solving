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

const int OFFSET = 500000;
int vertical[1000001] = {0, };
int horizontal[1000001] = {0, };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    vector<pii> pts;
    repeat(n) {
        int x, y; cin >> x >> y;
        pts.pb({x, y});
    }
    
    FOR(i, 0, n) {
        if(pts[i].fi == pts[(i+n-1)%n].fi) {
            vertical[min(pts[i].se, pts[(i+n-1)%n].se)+OFFSET]++;
            vertical[max(pts[i].se, pts[(i+n-1)%n].se)+OFFSET]--;
        }
        else {
            horizontal[min(pts[i].fi, pts[(i+n-1)%n].fi)+OFFSET]++;
            horizontal[max(pts[i].fi, pts[(i+n-1)%n].fi)+OFFSET]--;
        }
    }
    
    int ans = max(vertical[0], horizontal[0]);
    FOR(i, 1, 1000001) {
        vertical[i] += vertical[i-1];
        ans = max(ans, vertical[i]);
    }
    FOR(i, 1, 1000001) {
        horizontal[i] += horizontal[i-1];
        ans = max(ans, horizontal[i]);
    }
    
    cout << ans;
    
    return 0;
}
