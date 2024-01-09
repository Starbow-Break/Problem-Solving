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
bool isPrime[1000000] = {false, };
void getPrimes() {
    fill(isPrime+2, isPrime+1000000, true);
    for(int i = 2; i < 1000000; i++) {
        if(isPrime[i]) {
            primes.pb(i);
            for(int j = i; j < 1000000; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N; cin >> N;
    vector<int> vec(N);
    for(int i = 0; i < N; i++) cin >> vec[i];
    
    if(N == 1) {
        cout << 1; return 0;
    }
    
    getPrimes();
    
    int ans = 2;
    for(auto &p: primes) {
        if(2000000/p+(2000000%p > 0) <= ans) break;
        map<int, int> cnt;
        for(auto &v: vec) {
            auto t = cnt.find(v%p);
            if(t == cnt.end()) cnt.insert({v%p, 1});
            else {
                t->se++;
                ans = max(ans, t->se);
            }
        }
    }
    
    cout << ans;
    
    return 0;
}
