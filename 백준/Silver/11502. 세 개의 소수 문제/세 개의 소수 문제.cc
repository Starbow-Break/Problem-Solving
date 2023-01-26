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

bool isPrime[1000]; vector<int> primes;
void getPrimes() {
    fill(isPrime+2, isPrime+1000, true);
    
    for(int i = 2; i < 1000; i++) {
        if(isPrime[i]) {
            primes.push_back(i);
            for(int j = i; j < 1000; j += i) { isPrime[j] = false; }
        }
    }
}

void solve(int N) {
    for(int i = 0; i < primes.size(); i++) {
        for(int j = i; j < primes.size(); j++) {
            for(int k = 0; k < primes.size(); k++) {
                if(primes[i]+primes[j]+primes[k] == N) {
                    cout << primes[i] << " " << primes[j] << " "
                        << primes[k] << '\n';
                    return;
                }
            }    
        }
    }
    
    cout << "0" << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    getPrimes();
    
    int T; cin >> T;
    while(T--) {
        int N; cin >> N;
        solve(N);
    }

    return 0;
}