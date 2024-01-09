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

    int T; cin >> T;
    while(T--) {
        ll s; cin >> s;
        ll w = 1;
        ll ans = 0;
        while(w <= s) {
            for(int i = 1; i <= 9; i++) {
                int128 cur = i*w+ans;
                cur = cur*cur*cur;
                cur = cur%(10*w);
                if(cur == s%(10*w)) {
                    ans = i*w+ans;
                    
                    break;
                }
            }
            
            w *= 10;
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}
