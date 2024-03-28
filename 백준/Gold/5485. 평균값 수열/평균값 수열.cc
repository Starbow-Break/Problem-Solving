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

const int INF = 2e9;

map<int, int> cnt;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    vector<int> m(n), a(n);
    
    for(int i = 0; i < n; i++) {
        cin >> m[i];
        if(i == 0) a[i] = m[i];
        else a[i] = a[i-1] + (i%2 ? -1 : 1) * m[i];
    }
    
    for(int i = -1; i < n; i++) {
        int l, r;
        
        if(i == -1) {
            l = -INF; r = m[0];
        }
        else if(i == n-1) {
            int x1 = (m[i] - (i%2 ? -1 : 1) * 2 * a[i]) * ((i+1)%2 ? -1 : 1);
            int x2 = INF * ((i+1)%2 ? -1 : 1);
            l = min(x1, x2); r = max(x1, x2);
        }
        else {
            int x1 = (m[i] - (i%2 ? -1 : 1) * 2 * a[i]) * ((i+1)%2 ? -1 : 1);
            int x2 = (m[i+1] - (i%2 ? -1 : 1) * 2 * a[i]) * ((i+1)%2 ? -1 : 1);
            l = min(x1, x2); r = max(x1, x2);
        }
        
        auto tl = cnt.find(l);
        if(tl == cnt.end()) cnt.insert({l, 1});
        else tl->second++;
        
        auto tr = cnt.find(r+1);
        if(tr == cnt.end()) cnt.insert({r+1, -1});
        else tr->second--;
    }
    
    int ans = 0;
    int bef = -INF, weight = 0;
    for(auto &[x, delta]: cnt) {
        if(weight == n+1) {
            ans += x-bef;
        }
        
        bef = x; weight += delta;
    }
    
    cout << ans;
    
    return 0;
}