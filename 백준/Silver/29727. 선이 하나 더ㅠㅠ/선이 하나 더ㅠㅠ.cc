#include <bits/stdc++.h>
#define fi first
#define se second
#define repeat(n) for(int i = 0; i < n; i++)
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define push_back pb
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
    
    int n; cin >> n;
    int xa, ya, xb, yb; cin >> xa >> ya >> xb >> yb;
    
    ll ans = 1LL*n*(n+1)/2*n*(n+1)/2;
    
    if(xa == xb) {
        if(ya > yb) swap(ya, yb);
        ya = max(-1, min(n, ya));
        yb = max(-1, min(n, yb));
        ans += 1LL*(yb-ya)*(yb-ya-1)/2*(n+1);
    }
    if(ya == yb) {
        if(xa > xb) swap(xa, xb);
        xa = max(-1, min(n, xa));
        xb = max(-1, min(n, xb));
        ans += 1LL*(xb-xa)*(xb-xa-1)/2*(n+1);
    }
    
    cout << ans;
    
    return 0;
}