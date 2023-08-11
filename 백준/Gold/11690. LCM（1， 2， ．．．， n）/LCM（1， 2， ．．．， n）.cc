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

bool isPrime[100'000'000];
void getPrimes() {
    fill(isPrime+2, isPrime+100'000'000, true);
    for(int i = 2; i < 10'000; i++) {
        if(!isPrime[i]) continue;
        for(int j = i*2; j < 100'000'000; j += i) {
            isPrime[j] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    getPrimes();
    
    unsigned int ans = 1;
    int n; cin >> n;
    
    ll w = 2;
    while(w <= n) {
        ans *= 2;
        w *= 2;
    }
    
    for(int i = 3; i <= 100'000'000; i += 2) {
        if(isPrime[i]) {
            ll w = i;
            while(w <= n) {
                ans *= i;
                w *= i;
            }
        }
    }
    
    cout << ans;
    
    return 0;
}