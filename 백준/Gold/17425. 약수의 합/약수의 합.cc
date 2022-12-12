#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

ll f[1000001] = {0, };
ll g[1000001] = {0, };

bool isPrime[1001];
vector<int> primes;
void getPrimes() {
    fill(isPrime+2, isPrime+1001, true);
    for(int i = 2; i <= 1000; i++) {
        if(isPrime[i]) {
            primes.push_back(i);
            for(int j = i*2; j <= 1000; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

void getF() {
    for(int i = 1; i <= 1000000; i++) {
        f[i] = 1; ll w; int A = i;
        for(auto &p: primes) {
            if(A == 1) break;
            
            w = 1; ll ww = p;
            while(!(A%p)) {
                w += ww;
                ww *= p;
                A /= p;
            }
            
            f[i] *= w;
        }
        
        if(A != 1) f[i] *= 1+A;
    }
}

void getG() {
    getF();
    for(int i = 1; i <= 1000000; i++) {
        g[i] = g[i-1]+f[i];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    getPrimes();
    getG();
    
    int T; cin >> T;
    while(T--) {
        int N; cin >> N; cout << g[N] << '\n';
    }

    return 0;
}