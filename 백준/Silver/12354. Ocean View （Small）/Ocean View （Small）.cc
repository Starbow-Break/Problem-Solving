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
    
    int t; cin >> t;
    for(int tc = 1; tc <= t; tc++) {
        int n; cin >> n;
        vector<int> h(n);
        for(int i = 0; i < n; i++) cin >> h[i];
        vector<int> d; d.pb(h[0]);
        
        for(int i = 1; i < n; i++) {
            if(d.back() < h[i]) {
                d.pb(h[i]);
            }
            else {
                for(int j = 0; j < d.size(); j++) {
                    if(d[j] <= h[i]) {
                        d[j] = h[i];
                        break;
                    }
                }
            }
        }
        
        cout << "Case #" << tc << ": " << n-d.size() << '\n';
    }
    
    return 0;
}