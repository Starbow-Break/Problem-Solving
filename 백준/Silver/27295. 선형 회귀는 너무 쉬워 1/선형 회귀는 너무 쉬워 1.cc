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
    
    int n, b; cin >> n >> b;
    ll x = 0, y = 0;
    while(n--) {
        int _x, _y; cin >> _x >> _y;
        x += _x; y += b-_y;
    }
    
    if(!x) {
        cout << "EZPZ";
    }
    else {
        y *= -1;
        if(x < 0) { x *= -1; y *= -1; }
        ll g = gcd(abs(x), abs(y));
        x /= g; y /= g;
        if(x == 1) cout << y;
        else cout << y << '/' << x; 
    }
    
    return 0;
}