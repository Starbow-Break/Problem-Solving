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

bool isPrime[2500];

void getPrimes() {
    fill(isPrime+2, isPrime+2500, true);
    for(int i = 2; i < 2500; i++) {
        if(isPrime[i]) {
            if(i > 2000) {
                primes.pb(i);
            }
        
            for(int j = i*2; j < 2500; j += i) {
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
    
    int N, K; cin >> K >> N;
    
    for(int i = 0; i < K; i++) {
        for(int j = 0; j < N; j++) {
            cout << primes[i]*j+1 << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}