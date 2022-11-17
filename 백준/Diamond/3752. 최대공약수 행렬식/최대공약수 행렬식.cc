#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <cmath>
#define MOD 1000000007

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<double, double> dd;

bool isPrime[44730];
vector<int> prime;

void getPrime() {
    isPrime[0] = false; isPrime[1] = false;
    fill(isPrime+2, isPrime+44730, true);
    
    for(int i = 4; i < 44730; i += 2) { isPrime[i] = false; }
    
    for(int i = 3; i < 44730; i += 2) {
        if(isPrime[i]) {
            for(int j = i*2; j < 44730; j += i) { isPrime[j] = false; }
        }
    }
    
    for(int i = 2; i < 44730; i++) {
        if(isPrime[i]) prime.push_back(i);
    }
}

int eulerPhi(int value) {
    int ret = value;
    for(auto &p: prime) {
        if(!(value%p)) {
            ret /= p; ret *= (p-1);
            while(!(value%p)) { value /= p; }
        }
    }
    
    if(value > 1) {
        ret /= value; ret *= (value-1); 
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    getPrime();
    
    int T; cin >> T;
    while(T--) {
        int n; cin >> n;
        ll ans = 1;
        while(n--) {
            int v; cin >> v;
            ans *= eulerPhi(v);
            ans %= MOD;
        }
        
        cout << ans << '\n';
    }

    return 0;
}
