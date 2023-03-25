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

bool isPrime[100'000];
void getPrimes() {
    fill(isPrime+2, isPrime+100'000, true);
    
    for(int i = 2; i < 100'000; i++) {
        if(isPrime[i]) {
            primes.push_back(i);
            for(int j = i*2; j < 100'000; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    getPrimes();
    
    ll N; cin >> N;
    int ans = 0;
    
    vector<ll> open; open.push_back(1);
    for(auto &p : primes) {
        int j = open.size(); ll ub = N/(1LL*p*p);
        
        for(int i = 0; i < j; i++) {
            if(open[i] > ub) continue;
            
            ll cur = open[i]*p*p;
            while(cur <= N) {
                open.push_back(cur);
                cur *= 1LL*p*p;
            }
        }
    }
    
    cout << open.size();

    return 0;
}