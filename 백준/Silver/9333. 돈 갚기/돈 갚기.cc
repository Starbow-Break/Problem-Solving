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
        string sr, sb, sm; cin >> sr >> sb >> sm;
        int R = 0, B = 0, M = 0;
        
        for(auto &c: sr) {
            if(c != '.') R = R*10 + (c-'0');
        }
        
        for(auto &c: sb) {
            if(c != '.') B = B*10 + (c-'0');
        }
        
        for(auto &c: sm) {
            if(c != '.') M = M*10 + (c-'0');
        }
        
        int ans = 0;
        ll remain = B;
        while(true) {
            ans++;
            if(ans > 1200) {
                cout << "impossible" << '\n';
                break;
            }
            
            remain = 1LL*remain*(10000+R)/10000 + (1LL*remain*(10000+R) % 10000 >= 5000);
            remain -= M;
            
            if(B <= remain) {
                cout << "impossible" << '\n';
                break;
            }
            
            if(remain <= 0) {
                cout << ans << '\n';
                break;
            }
        }
    }
    
    return 0;
}