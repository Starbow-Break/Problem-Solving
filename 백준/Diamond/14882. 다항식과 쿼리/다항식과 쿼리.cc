#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <map>
#include <iomanip>
#include <complex>
#define x first
#define y second
#define MOD 786'433

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef __int128_t int128;

//a^e % mod
ll modPow(ll a, ll e, ll mod) {
    ll ret = 1, w = a;
    
    while(e > 0) {
        if(e%2) {
            ret *= w; ret %= mod;
        }
        w *= w; w %= mod;
        e /= 2;
    }
    
    return ret;
}

//mod에 대해서 v^-1
//NTT를 사용할 때는 mod가 소수임이 보장된다.
ll inverse(ll v, ll mod) {
    return modPow(v, mod-2, mod);
}

//NTT
template<int mod, int pri>
void ntt(vector<ll> &A, bool inv = false) {
    int sz = A.size();
    
    //NTT를 수행할 수 있도록 적절하게 정렬
    for(int i = 0; i < sz; i++) {
        int j = 0;
        for(int t = 1; t < sz; t <<= 1) {
            j <<= 1; j |= ((i & t) != 0);
        }
        
        if(i < j) swap(A[i], A[j]);
    }
    
    //NTT 실시
    for(int len = 2; len <= sz; len <<= 1) {
        ll w = modPow(pri, (mod-1)/len, mod);
        if(inv) w = inverse(w, mod);
        
        for(int i = 0; i < sz; i += len) {
            ll e = 1;
            for(int j = 0; j < len/2; j++) {
                ll odd = A[i+j+len/2], even = A[i+j];
                A[i+j] = (even+e*odd)%mod;
                A[i+j+len/2] = (even+(mod-e)*odd)%mod;
                e *= w; e %= mod;
            }
        }
    }
    
    if(inv) {
        for(int i = 0; i < sz; i++) {
            A[i] *= inverse(sz, mod); A[i] %= mod;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    vector<ll> f[3], _f(1 << 18);
    f[0].resize(1<<18); f[1].resize(1<<18); f[2].resize(1<<18);
    
    int pow10[MOD]; //pow10[i] = 10^i
    int invPow10[MOD]; //pow10의 역함수
    pow10[0] = 1;
    for(int i = 1; i < MOD; i++) {
        pow10[i] = pow10[i-1]*10;
        pow10[i] %= MOD;
    }
    
    for(int i = 0; i < MOD-1; i++) invPow10[pow10[i]] = i;
    
    for(int i = 0; i <= N; i++) {
        cin >> f[0][i]; _f[i] = f[0][i];
        f[1][i] = 1LL*f[0][i]*pow10[i]%MOD;
        f[2][i] = 1LL*f[0][i]*pow10[2*i]%MOD;
    }
    
    //다항식의 최대 차수는 250000
    //786433 = 2^18*3+1이므로 사용 가능하다.
    for(int i = 0; i < 3; i++) ntt<MOD, 10>(f[i]);
    
    int K; cin >> K;
    while(K--) {
        int v; cin >> v;
        if(v == 0) cout << _f[0];
        else {
            int q = invPow10[v]/3, r = invPow10[v]%3;
            int ans = f[r][q];
            cout << ans;
        }
        
        cout << '\n';
    }
    
    return 0;
}