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
 
vector<star> stars; // 별들의 정보
 
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
    FOR(i, b, d+1) {
        for(auto &[x, y, p]: stars) {
            int l = max(a, x-p+abs(i-y));
            int r = min(c, x);
            if(l <= r) {
                l -= x-p+abs(i-y);
                r -= x-p+abs(i-y);
                ans += 1LL*(l+r)*(r-l+1)/2;
            }
            
            l = max(a, x+1);
            r = min(c, x+p-abs(i-y));
            if(l <= r) {
                l = x+p-abs(i-y)-l;
                r = x+p-abs(i-y)-r;
                ans += 1LL*(l+r)*(l-r+1)/2;
            }
        }
    }
    
    cout << ans;
 
    return 0;
}