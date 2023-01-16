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

bool isPrime[33000];
void getPrime() {
    fill(isPrime+2, isPrime+33000, true);
    
    for(int i = 2; i < 33000; i++) {
        if(isPrime[i]) {
            primes.push_back(i);
            for(int j = i*2; j < 33000; j += i) { isPrime[j] = false; }
        }
    }
}

int phi(int x) {
    int ret = x;
    
    for(auto &p: primes) {
        if(x%p == 0) {
            ret /= p; ret *= (p-1);
        }
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    getPrime();
    
    int n; cin >> n;
    
    int ans = -1;
    for(int i = floor(sqrt(n)); i >= 1; i--) {
        if(n%i == 0) {
            int x = n/i;
            if(phi(x) == i) { ans = x; break; }
        }
    }
    
    cout << ans;

    return 0;
}