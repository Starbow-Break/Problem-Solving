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
bool isPrime[100000];
void getPrimes() {
    fill(isPrime+2, isPrime+100000, true);
    
    for(int i = 2; i < 100000; i++) {
        if(isPrime[i]) {
            primes.push_back(i);
            for(int j = i; j < 100000; j += i) isPrime[j] = false;
        }
    }
}

int phi(int N) {
    if(N == 1) return 0;
    
    int ret = N; int cur = N;
    
    for(auto &p: primes) {
        if(cur%p == 0) {
            ret /= p; ret *= (p-1);
            while(cur%p == 0) cur /= p;
        }
    }
    
    if(cur != 1) { ret /= cur; ret *= (cur-1); }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    getPrimes();
    
    ll N;
    while(1) {
        cin >> N;
        if(N == 0) break;
        
        cout << phi(N) <<'\n';
    }

    return 0;
}