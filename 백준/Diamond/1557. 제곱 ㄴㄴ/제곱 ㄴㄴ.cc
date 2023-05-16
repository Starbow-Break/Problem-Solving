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

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

vector<int> primes;

bool isPrime[64000];
void getPrimes() {
    fill(isPrime+2, isPrime+64000, true);
    for(int i = 2; i < 64000; i++) {
        if(isPrime[i]) {
            primes.push_back(i);
            for(int j = 2*i; j < 64000; j += i) isPrime[j] = false;
        }
    }
}

ll numSquareFree(ll value, int cur = 1, int start = 0) {
    ll ret = 0;
    
    for(int i = start; i < primes.size(); i++) {
        int p = cur*primes[i]; 
        if(value < 1LL*p*p) break;
        
        ret += value/(1LL*p*p);

        if(value >= 1LL*p*primes[i+1]*p*primes[i+1])
            ret -= numSquareFree(value, p, i+1);
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    getPrimes();
    
    ll K; cin >> K;
    
    ll i = 1, j = 4'000'000'000;
    while(i <= j) {
        ll mid = (i+j)>>1;
        ll k = numSquareFree(mid);
        
        if(mid-k < K) i = mid+1;
        else j = mid-1;
    }
    
    cout << i;

    return 0;
}