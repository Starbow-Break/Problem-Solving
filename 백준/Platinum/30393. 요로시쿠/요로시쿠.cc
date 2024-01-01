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

const int MOD = 998'244'353;

ll modpow(int a, int e) {
    ll ret = 1, w = a;
    while(e > 0) {
        if(e & 1) {
            ret *= w;
            ret %= MOD;
        }
        
        w *= w;
        w %= MOD;
        e >>= 1;
    }
    
    return ret;
}

int inverse(int value) {
    return modpow(value, MOD-2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M; cin >> N >> M;
    vector<int> vec(N);
    
    int X = 0;
    for(int i = 0; i < N; i++) {
        cin >> vec[i];
        X += vec[i];
    }
    
    if(M == 1) {
        cout << 0;
        return 0;
    }
    
    int A = 1LL*(M-1)*M%MOD*inverse(1LL*X*(X-1)%MOD)%MOD;
    int B = 0;
    int inv2 = inverse(2);
    
    for(int i = 0; i < N; i++) {
        B += 1LL*vec[i]*(vec[i]-1)%MOD*inv2%MOD;
        B %= MOD;
    }
    
    cout << 1LL*A*B%MOD;
    
    return 0;
}
