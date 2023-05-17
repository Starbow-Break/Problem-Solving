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

bool isPrime[32000];
vector<int> primes;
void getPrimes() {
    fill(isPrime+2, isPrime+32000, true);
    for(int i = 2; i < 32000; i++) {
        if(isPrime[i]) {
            primes.push_back(i);
            for(int j = i*2; j < 32000; j += i) isPrime[j] = false;
        }
    }
}

int query(int value, int p, int cur = 1, int start = 0) {
    int ret = 0;
    
    for(int i = start; i < primes.size(); i++) {
        if(primes[i] >= p) break;
        if(primes[i] > value/cur) break;
        
        ret += value/(cur*primes[i]);
        
        if(cur <= value/primes[i]) ret -= query(value, p, cur*primes[i], i+1);
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, P; cin >> N >> P;
    
    if(P > sqrt(1'000'000'000)) {
        if(N == 1) cout << P;
        else cout << 0;
    }
    else {
        getPrimes();
        int i = 1, j = 1e9/P;
        while(i <= j) {
            int mid = (i+j)>>1;
            int k = query(mid, P);
            
            if(mid-k < N) i = mid+1;
            else j = mid-1;
        }
        
        cout << (i > 1e9/P ? 0 : P*i);
    }

    return 0;
}