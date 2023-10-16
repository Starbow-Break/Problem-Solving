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

bool isPrime[1000001] = {false, };
vector<int> primes;
void getPrimes() {
    fill(isPrime+2, isPrime+1000001, true);
    for(int i = 2; i <= 1000000; i++) {
        if(isPrime[i]) {
            primes.pb(i);
            for(int j = i*2; j <= 1000000; j += i) isPrime[j] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    getPrimes();
    
    int M; cin >> M;
    switch(M%6) {
        case 0:
        cout << M/3;
        break;
        case 1:
        cout << M/3+1;
        break;
        case 2:
        cout << M/3+1;
        break;
        case 3:
        cout << M/3;
        break;
        case 4:
        cout << M/3+1;
        break;
        case 5:
        cout << M/3+1;
    }
    
    cout << ' ';
    
    if(M == 1) cout << 1;
    else {
        int len = 0;
        for(auto &p: primes) {
            int cur = 0;
            while(M%p == 0) {
                M /= p;
                cur++;
            }
            
            if(p == 2) len += (cur+1)/2;
            else len += cur;
        }
        
        cout << len;
    }
    
    return 0;
}