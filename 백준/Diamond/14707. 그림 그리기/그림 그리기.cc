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

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef __int128_t int128;

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

ll inverse(ll v, ll mod) {
    return modPow(v, mod-2, mod);
}

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
        
        ll t = modPow(w, (mod-1)/2, mod);
        
        for(int i = 0; i < sz; i += len) {
            ll e = 1;
            for(int j = 0; j < len/2; j++) {
                ll odd = A[i+j+len/2], even = A[i+j];
                A[i+j] = (even+e*odd)%mod;
                A[i+j+len/2] = (even+(mod-e)*t%mod*odd)%mod;
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

template<int mod, int pri>
vector<ll> polyMultiple(vector<ll> A, vector<ll> B) {
    int sz = 1;
    while(sz < A.size() || sz < B.size()) sz <<= 1;
    sz <<= 1;
    
    A.resize(sz); B.resize(sz);
    vector<ll> ret(sz);
    
    ntt<mod, pri>(A); ntt<mod, pri>(B);
    for(int i = 0; i < sz; i++) {
        ret[i] = (A[i]*B[i])%mod;
    }

    ntt<mod, pri>(ret, true);
    
    /*for(int i = 0; i < sz; i++) {
        cout << ret[i] << ' ';
    }
    cout << '\n';*/
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int mod1 = 1'092'616'193; int mod2 = 2'113'929'217;
    
    int N, M, L; cin >> N >> M >> L;
    vector<ll> R(123456), C(123456);
    

    for(int i = 0; i < N; i++) {
        int r; cin >> r;
        R[(1LL*M*i)%L] += r;
    }
        
    for(int i = 0; i < M; i++) {
        int r; cin >> r;
        C[i] = r;
    }
    
    vector<ll> RC1 = polyMultiple<1'092'616'193, 3>(R, C);
    vector<ll> RC2 = polyMultiple<2'113'929'217, 5>(R, C);
    
    ll ans[L] = {0, };

    for(int i = 0; i < L; i++) {
        for(int j = i; j < RC1.size(); j += L) {
            ans[i] += ((int128)1*mod2*inverse(mod2%mod1, mod1)*RC1[j]+(int128)1*mod1*inverse(mod1%mod2, mod2)*RC2[j])%(1LL*mod1*mod2);
        }
    }
    
    for(int i = 0; i < L; i++) cout << ans[i] << '\n';
    
    return 0;
}