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
bool isPrime[1000000];
void getPrimes() {
    fill(isPrime+2, isPrime+1000000, true);
    for(int i = 2; i < 1000000; i++) {
        if(!isPrime[i]) continue;
        primes.pb(i);
        for(int j = i*2; j < 1000000; j += i) {
            isPrime[j] = false;
        }
    }
}

bool check(ll X) {
    ll i = 1, j = 1000000000;
    while(i <= j) {
        ll mid = i+j >> 1;
        if(mid*mid == X) return true;
        
        if(mid*mid < X) i = mid+1;
        else j = mid-1;
    }
    return false;
}

bool solve(ll X) {
    if(X == 1) return true;
    
    for(auto &p: primes) {
        int cnt = 0;
        while(X%p == 0) {
            X /= p;
            cnt++;
        }
        
        if(cnt%2) return false;
    }
    
    return check(X);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    getPrimes();
    
    int N; cin >> N;
    while(N--) {
        ll X; cin >> X;
        cout << solve(X) << ' ';
    }
    
    return 0;
}