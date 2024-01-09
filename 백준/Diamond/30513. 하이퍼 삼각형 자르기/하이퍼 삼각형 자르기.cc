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
ll factorial[200'001];

void getFactorial() {
    factorial[0] = 1;
    for(int i = 1; i <= 200'000; i++) {
        factorial[i] = factorial[i-1] * i % MOD;
    }
}

ll modpow(ll a, ll e) {
    ll ret = 1; ll w = a;
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

ll inverse(ll v) {
    return modpow(v, MOD-2);
}

ll combination(int n, int m) {
    if(n < m) return 0;
    
    return factorial[n] * inverse(factorial[m]) % MOD * inverse(factorial[n-m]) % MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int M, N; cin >> M >> N;
    
    // a = combination(N+M, M+1)
    // b = combination(N, M)+combination(N-M, M)+...+combination(N-M(k-1), M)+...
    // answer = (a+b) % MOD
    ll a = 0, b = 0;
    
    // 팩토리얼 값 먼저 계산
    getFactorial();
    
    // a 계산
    a = combination(N+M, M+1);
    
    // b 계산
    for(int i = N; i >= M; i -= M) {
        b += combination(i, M);
        b %= MOD;
    }
    
    cout << (a+b) % MOD;
    
    return 0;
}
