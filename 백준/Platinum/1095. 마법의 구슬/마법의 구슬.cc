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

vector<pii> factorization[100'001];
vector<int> primes;
bool isPrime[100'000];

void getPrimes() {
    fill(isPrime+2, isPrime+100'000, true);
    for(int i = 2; i < 100'000; i++) {
        if(isPrime[i]) {
            primes.pb(i);
            for(int j = i*2; j < 100'000; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

void getFactorization() {
    int arr[100'001];
    for(int i = 2; i <= 100'000; i++) arr[i] = i;
    
    for(auto &p: primes) {
        for(int i = p; i <= 100'000; i += p) {
            int cnt = 0;
            while(arr[i]%p == 0) {
                arr[i] /= p;
                cnt++;
            }
            factorization[i].pb({p, cnt});
        }
    }
}

int calc(int num, int factor) {
    int ret = 0;
    while(num >= factor) {
        ret += num/factor;
        num /= factor;
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    getPrimes();
    getFactorization();
    
    int S, F, M; cin >> S >> F >> M;
    for(int i = M; i >= 2; i--) {
        bool check = true;
        for(auto &[p, cnt]: factorization[i]) {
            int a = calc(S+F, p);
            int b = calc(S, p);
            int c = calc(F, p);
            if(a-(b+c) < cnt) {
                check = false;
                break;
            }
        }
        
        if(check) {
            cout << i;
            return 0;
        }
    }
    
    cout << 1;
    
    return 0;
}
