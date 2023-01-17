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

bool isPrime[330];
void getPrimes() {
    fill(isPrime+2, isPrime+330, true);
    for(int i = 2; i < 330; i++) {
        if(isPrime[i]) {
            primes.push_back(i);
            for(int j = i*2; j < 330; j += i) { isPrime[j] = false; }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    getPrimes();
    
    int T; cin >> T;
    while(T--) {
        int N; cin >> N;
        for(auto &p: primes) {
            if(!(N%p)) {
                int cnt = 0;
                while(!(N%p)) { N /= p; cnt++; }
                cout << p << " " << cnt << '\n';
            }
        }
        
        if(N > 1) cout << N << " " << 1 << '\n';
    }

    return 0;
}