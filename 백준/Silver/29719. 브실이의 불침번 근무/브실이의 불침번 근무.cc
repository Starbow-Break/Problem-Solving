#include <bits/stdc++.h>
#define fi first
#define se second
#define repeat(n) for(int i = 0; i < n; i++)
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define pb push_back 
#define all(vec) vec.begin(), vec.end()
#define rall(vec) vec.rbegin(), vec.rend()
#define compress(vec) sort(all(vec)); vec.erase(unique(all(vec)), vec.end());

const int MOD = 1'000'000'007;

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;
using int128 = __int128_t;

ll modPow(int n, int m) {
    ll ret = 1; ll w = n;
    while(m > 0) {
        if(m&1) {
            ret *= w; ret %= MOD;
        }
        w *= w; w %= MOD;
        m /= 2;
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M; cin >> N >> M;
    cout << (modPow(M, N)+MOD-modPow(M-1, N))%MOD;
    
    return 0;
}