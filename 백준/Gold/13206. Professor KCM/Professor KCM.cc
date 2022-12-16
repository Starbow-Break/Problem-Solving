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
vector<int> values;

bool isPrime[1001];
void getPrimes() {
    fill(isPrime+2, isPrime+1001, true);
    for(int i = 2; i <= 1000; i++) {
        if(isPrime[i]) {
            primes.push_back(i);
            for(int j = i*2; j <= 1000; j += i) { isPrime[j] = false; }
        }
    }
}

ll modPow(int a, int e) {
    ll ret = 1; ll w = a;
    
    while(e > 0) {
        if(e%2) {
            ret *= w; ret %= MOD;
        }
        
        w *= w; w %= MOD;
        e /= 2;
    }
    
    return ret;
}

ll lcm() {
    ll ret = 1;
    
    for(auto &p: primes) {
        int maxCnt = 0;
        for(int i = 0; i < values.size(); i++) {
            int cnt = 0;
            while(!(values[i]%p)) {
                cnt++; values[i] /= p;
            }
            
            maxCnt = max(maxCnt, cnt);
        }
        
        ret *= modPow(p, maxCnt); ret %= MOD;
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    getPrimes();
    
    int T; cin >> T;
    while(T--) {
        values.clear();
        
        int N; cin >> N;
        while(N--) {
            int v; cin >> v;
            values.push_back(v);
        }
        
        cout << lcm() << '\n';
    }

    return 0;
}