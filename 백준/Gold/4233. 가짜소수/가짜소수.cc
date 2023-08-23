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

vector<int> primes;
bool isPrime[33000];
void getPrimes() {
    fill(isPrime+2, isPrime+33000, true);
    for(int i = 2; i <= 33000; i++) {
        if(!isPrime[i]) continue;
        primes.pb(i);
        for(int j = i*2; j <= 33000; j += i) {
            isPrime[j] = false;
        }
    }
}

bool checkPrime(int v) {
    for(auto &p: primes) {
        if(p != v && v%p == 0) return false;
    }
    return true;
}

ll modPow(int a, int e, int mod) {
    ll ret = 1, w = a;
    while(e > 0) {
        if(e&1) {
            ret *= w;
            ret %= mod;
        }
        e /= 2;
        w *= w; w %= mod;
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    getPrimes();
    
    int p, a; 
    while(cin >> p >> a) {
        if(!a && !p) break;
        
        if(checkPrime(p)) {
            cout << "no" << '\n';
            continue;
        }
        
        if(modPow(a, p, p) == a) cout << "yes" << '\n';
        else cout << "no" << '\n';
    }
    
    return 0;
}
