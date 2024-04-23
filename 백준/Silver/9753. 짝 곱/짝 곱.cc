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
vector<int> prods;

bool isPrime[100'002];
void getPrimes() {
    fill(isPrime+2, isPrime+100'002, true);
    
    for(int i = 2; i < 100'002; i++) {
        if(isPrime[i]) {
            primes.pb(i);
            for(int j = i; j < 100'002; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    getPrimes();
    
    for(int i = 0; i < primes.size(); i++) {
        for(int j = i+1; j < primes.size(); j++) {
            if(1LL*primes[i]*primes[j] <= 100'001) {
                prods.pb(primes[i]*primes[j]);
            }
            else break;
        }
    }
    
    sort(all(prods));
    
    int T; cin >> T;
    while(T--) {
        int v; cin >> v;
        for(auto &p: prods) {
            if(v <= p) {
                cout << p << '\n';
                break;
            }
        }
    }
    
    return 0;
}
