#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<double, double> dd;

vector<int> primes;
bool isPrime[2301];

void getPrimes() {
    fill(isPrime+2, isPrime+2301, true);
    
    for(int i = 2; i <= 2300; i++) {
        if(isPrime[i]) {
            primes.push_back(i);
            for(int j = i*2; j <= 2300; j += i) { isPrime[j] = false; }
        }
    }
}

void primeFactorization(int value) {
    for(auto &p: primes) {
        if(value == 1) break;
        while(!(value%p)) {
            cout << p << " ";
            value /= p;
        }
    }
    
    if(value > 1) cout << value;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    getPrimes();
    
    int N; cin >> N;
    while(N--) {
        int v; cin >> v;
        primeFactorization(v); cout << '\n';
    }

    return 0;
}