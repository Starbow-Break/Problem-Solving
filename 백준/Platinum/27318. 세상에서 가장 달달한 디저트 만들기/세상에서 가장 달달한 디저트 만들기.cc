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

const int MOD = 1'000'000'007;

ll modPow(ll a, ll e) {
    ll ret = 1, w = a;
    while(e) {
        if(e&1) {
            ret *= w; ret %= MOD;
        }
        w *= w; w %= MOD;
        e >>= 1;
    }
    
    return ret;
}

ll inverse(int v) {
    return modPow(v, MOD-2);
}

int volume(ll N, ll M) {
    return modPow(12*N-16, M);
}

int surface(ll N, ll M) {
    ll a = modPow(12*N-16, M)*6%MOD;
    ll b = 24*(N-1)%MOD;
    b *= (modPow(12*N-16, M)+MOD-modPow(4*N-4, M))%MOD;
    b %= MOD;
    b *= inverse(8*N-12); b %= MOD;
    return (a+MOD-b)%MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll N, M; cin >> N >> M;
    
    cout << volume(N, M) << ' ' << surface(N, M);
    
    return 0;
}
