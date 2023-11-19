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
 
struct star {
    int x, y, p;
};
 
vector<star> stars;
 
ll subcalc(int n) {
    return 1LL*n*(n+1)*(n+1)/2-1LL*n*(n+1)*(2*n+1)/6;
}
 
ll calc(int x, int y, int p, int a, int b, int c, int d) {
    if(a <= x && x <= c && b <= y && y <= d) {
        int p1 = y+p-1-d, p2 = a-x+p-1, p3 = p1+p2-p;
        //cout << p1 << ' ' << p2 << ' ' << p3 << '\n';
        return subcalc(p)-subcalc(max(0, p1))-subcalc(max(0, p2))+subcalc(max(0, p3));
    }
    else {
        if(x < a || y > d) return 0;
        else {
            int pp = max(0, p-max(0, x-c)-max(0, b-y));
            if(pp) {
                return calc(min(x, c), max(b, y), pp, a, b, c, d);
            }
            else return 0;
        }
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    repeat(N) {
        int x, y, p; cin >> x >> y >> p;
        stars.pb({x, y, p});
    }
    int a, b, c, d; cin >> a >> b >> c >> d;
    
    ll ans = 0;
    FOR(i, 0, N) {
        int x = stars[i].x, y = stars[i].y, p = stars[i].p;
        if(a <= x && x <= c && b <= y && y <= d) ans += p;
        ans += calc(x-a-1, y-b, p-1, 0, 0, c-a, d-b);
        ans += calc(d-y-1, x-a, p-1, 0, 0, d-b, c-a);
        ans += calc(c-x-1, d-y, p-1, 0, 0, c-a, d-b);
        ans += calc(y-b-1, c-x, p-1, 0, 0, d-b, c-a);
    }
    
    cout << ans;
    
    return 0;
}