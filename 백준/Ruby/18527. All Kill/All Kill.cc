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

const int MOD = 998244353;

ll modPow(int a, int e) {
    ll ret = 1; ll w = a;
    while(e > 0) {
        if(e&1) {
            ret *= w;
            ret %= MOD;
        }
        
        e /= 2;
        w *= w; w %= MOD;
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, t; cin >> n >> t;
    t++;
    
    ll ans = 1;
    vector<int> x;
    repeat(n) {
        int v; cin >> v;
        x.pb(v);
    }
    
    for(int i = n-1; i >= 0; i--) {
        t -= (x[i]-1);
        ans *= t;
        ans %= MOD;
    }
    
    ans *= t-n;
    ans %= MOD;
    ans *= modPow(t, MOD-2);
    ans %= MOD;
    
    cout << ans;
    
    return 0;
}
