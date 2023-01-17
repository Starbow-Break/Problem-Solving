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

bool isPrime[8000000];
vector<int> primes;

void getPrimes() {
    fill(isPrime+2, isPrime+8000000, true);
    
    for(int i = 2; i < 8000000; i++) {
        if(isPrime[i]) {
            primes.push_back(i);
            for(int j = i*2; j < 8000000; j += i) {
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
    
    int K; cin >> K;
    cout << primes[K-1];

    return 0;
}