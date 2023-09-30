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
bool isPrime[10000];

void getPrimes() {
    fill(isPrime+2, isPrime+10000, true);
    for(int i = 2; i < 10000; i++) {
        if(isPrime[i]) {
            primes.pb(i);
            for(int j = i*2; j < 10000; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

bool checkPrime(int v) {
    for(auto &p: primes) {
        if(v > p && v%p == 0) return false;
    }
    return true;
}

vector<int> solve(int N) {
    vector<int> ret;
    if(N%2) {
        ret.pb(2); ret.pb(3);
        N -= 5;
    }
    else {
        ret.pb(2); ret.pb(2);
        N -= 4;
    }
    
    if(checkPrime(2) && checkPrime(N-2)) {
        ret.pb(2); ret.pb(N-2);
    }
    else {
        for(int i = 3; i <= N/2; i += 2) {
            if(checkPrime(i) && checkPrime(N-i)) {
                ret.pb(i); ret.pb(N-i);
                break;
            }
        }
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    getPrimes();
    
    int N;
    while(cin >> N) {
        if(N < 8) cout << "Impossible." << '\n';
        else {
            vector<int> ans = solve(N);
            for(auto &a: ans) cout << a << ' ';
            cout << '\n';
        }
    }
    
    return 0;
}