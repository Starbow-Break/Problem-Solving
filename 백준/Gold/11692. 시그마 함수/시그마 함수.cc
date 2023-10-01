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

bool isPrime[1'000'000];
vector<int> primes;
void getPrimes() {
    fill(isPrime+2, isPrime+1'000'000, true);
    for(int i = 2; i < 1'000'000; i++) {
        if(isPrime[i]) {
            primes.pb(i);
            for(int j = i*2; j < 1'000'000; j += i) isPrime[j] = false;
        }
    }
}

ll calc(ll ub, int idx = 0) {
    if(idx == primes.size()) return 1;
    
    ll ret = 1;
    int p = primes[idx];
    if(idx == 0) {
        ll w = 1;
        while(ub >= p) {
            ret += calc(ub, idx+1);
            w *= p; ub /= p;
        }
    }
    else {
        ll w = 1;
        while(ub >= 1LL*p*p) {
            ret += calc(ub, idx+1);
            w *= 1LL*p*p;
            ub /= 1LL*p*p;
        }
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll m; cin >> m;
    getPrimes();
    
    cout << m-calc(m);
    
    return 0;
}
