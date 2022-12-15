#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <cmath>
#define MOD 1000000007

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

vector<int> primes;
vector<int> primeFactors;

bool isPrime[32000];
void getPrimes() {
    fill(isPrime+2, isPrime+32001, true);
    for(int i = 2; i <= 32000; i++) {
        if(isPrime[i]) {
            primes.push_back(i);
            for(int j = i*2; j <= 32000; j += i) { isPrime[j] = false; }
        }
    }
}

void getPrimeFactors(int N) {
    for(auto &p: primes) {
        if(!(N%p)) {
            primeFactors.push_back(p);
            while(!(N%p)) { N /= p; }
        }
    }
    
    if(N > 1) { primeFactors.push_back(N); }
}

ll solve(ll A, ll B) {
    ll ret = B-A+1; int l = primeFactors.size();
    for(int state = 1; state < (1<<l); state++) {
        int cnt = 0; int prod = 1;
        for(int i = 0; i < l; i++) {
            if(state & (1<<i)) {
                cnt++; prod *= primeFactors[i];
            }
        }
        
        if(cnt%2) ret -= (B/prod-(A-1)/prod);
        else ret += (B/prod-(A-1)/prod);
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    getPrimes();
    
    int T; cin >> T;
    for(int i = 1; i <= T; i++) {
        primeFactors.clear();
        
        ll A, B; int N; cin >> A >> B >> N;
        getPrimeFactors(N);
        
        cout << "Case #" << i << ": " << solve(A, B) << '\n';
    }

    return 0;
}
