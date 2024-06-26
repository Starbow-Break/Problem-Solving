#include <bits/stdc++.h>
#define fi first
#define se second
#define repeat(n) for(int i = 0; i < n; i++)
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORIter(v, vec) for(auto &v: vec)
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
    while(t--) {
        char s[17]; cin >> s;

        int sz;
        for(sz = 0; s[sz] != '\0'; sz++) {}
        
        sort(s, s+sz);
        
        ll ans = 0;
        for(int i = sz-1; i >= 1; i--) {
            ans = 10 * ans + (s[i] - '0');
        }
        
        ans += (s[0] - '0');
        
        cout << ans << '\n';
    }
    
    return 0;
}
