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

bool isPrime(ll N) {
    for(ll i = 2; i <= sqrt(N); i++) {
        if(N%i == 0) return false;
    }
    
    return true;
}

ll nextPrime(ll N) {
    if(N <= 2) return 2;
    
    while(1) {
        if(isPrime(N)) {
            return N; break;
        }
        
        N++;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T; cin >> T;
    while(T--) {
        ll N; cin >> N;
        cout << nextPrime(N) << '\n';
    }
    
    return 0;
}