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

ll solve(int X, int Y, int x, int y) {
    int qx = X/x, qy = Y/y;
    int rx = X%x, ry = Y%y;
    
    return 1LL*rx*ry*max(1LL*((qx+2)/2)*((qy+2)/2), 1LL*((qx+1)/2)*((qy+1)/2))
        + 1LL*rx*(y-ry)*max(1LL*((qx+2)/2)*((qy+1)/2), 1LL*((qx+1)/2)*(qy/2))
        + 1LL*(x-rx)*ry*max(1LL*((qx+1)/2)*((qy+2)/2), 1LL*(qx/2)*((qy+1)/2))
        + 1LL*(x-rx)*(y-ry)*max(1LL*((qx+1)/2)*((qy+1)/2), 1LL*(qx/2)*(qy/2))
        + 1LL*rx*ry*max(1LL*((qx+1)/2)*((qy+2)/2), 1LL*((qx+2)/2)*((qy+1)/2))
        + 1LL*rx*(y-ry)*max(1LL*((qx+1)/2)*((qy+1)/2), 1LL*((qx+2)/2)*(qy/2))
        + 1LL*(x-rx)*ry*max(1LL*(qx/2)*((qy+2)/2), 1LL*((qx+1)/2)*((qy+1)/2))
        + 1LL*(x-rx)*(y-ry)*max(1LL*(qx/2)*((qy+1)/2), 1LL*((qx+1)/2)*(qy/2));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T; cin >> T;
    
    while(T--) {
        int X, Y, x, y; cin >> X >> Y >> x >> y;
        cout << solve(X, Y, x, y) << '\n';
    }
    
    return 0;
}
