#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <list>
#include <map>
#include <cmath>
#include <iomanip>
#define MOD 1'000'000'007

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

vector<int> primes;
bool isPrime[1'000'001]; int phi[1'000'001];
void getPrimes() {
    fill(isPrime+2, isPrime+1'000'001, true);
    for(int i = 2; i <= 1'000'000; i++) {
        if(isPrime[i]) {
            primes.push_back(i);
            for(int j = 2*i; j <= 1'000'000; j += i) isPrime[j] = false;
        }
    }
}

void getPhi() {
    for(int i = 1; i <= 1'000'000; i++) phi[i] = i;
    
    getPrimes();
    
    for(auto &p : primes) {
        for(int i = p; i <= 1'000'000; i += p) {
            phi[i] = 1LL*phi[i]*(p-1)/p;
        }
    }
}

int inverse(int v) {
    ll ret = 1;
    ll w = v; int e = MOD-2;
    while(e > 0) {
        if(e%2) {
            ret *= w; ret %= MOD;
        }
        
        e /= 2;
        w *= w; w %= MOD;
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    getPhi();
    
    ll ans = 0;
        
    for(int i = 1; i <= N; i++) {
        ans += 1LL*i*phi[i]%MOD*(1LL*(N/i)*(N/i+1)/2%MOD*i%MOD);
        ans %= MOD;
    }
    ans += (MOD-1LL*N*(N+1)/2%MOD); ans %= MOD;
    ans *= inverse(2); ans %= MOD;
        
    cout << ans;

    return 0;
}