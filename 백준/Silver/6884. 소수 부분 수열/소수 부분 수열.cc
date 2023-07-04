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
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef __int128_t int128;

ostream& operator<<(ostream &out, const pii &p) {
    out << p.first << ' ' << p.second;
    return out;
}

bool isPrime[10001];
vector<int> primes;

void getPrimes() {
    isPrime[1] = false;
    fill(isPrime+2, isPrime+10001, true);
    for(int i = 2; i <= 10000; i++) {
        if(isPrime[i]) {
            primes.push_back(i);
            for(int j = i*2; j <= 10000; j += i) isPrime[j] = false;
        }
    }
}

bool checkPrime(int v) {
    if(v <= 10000) return isPrime[v];
    
    for(auto &p: primes) {
        if(v%p == 0) return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    getPrimes();
    
    int T; cin >> T;
    while(T--) {
        int N; cin >> N;
        int sum[10001]; sum[0] = 0;
        for(int i = 1; i <= N; i++) {
            cin >> sum[i];
            sum[i] += sum[i-1];
        }
        
        vector<int> ans;
        for(int i = 2; i <= N; i++) {
            for(int j = 1; j <= N-i+1; j++) {
                int k = j+i-1;
                int s = sum[k]-sum[j-1];
                if(checkPrime(s)) {
                    for(int l = j; l <= k; l++) {
                        ans.push_back(sum[l]-sum[l-1]);
                    }
                    break;
                }
            }
            if(ans.size() > 0) break;
        }
        
        if(ans.size() == 0) cout << "This sequence is anti-primed.";
        else {
            cout << "Shortest primed subsequence is length " << ans.size() << ": ";
            for(auto &v : ans) cout << v << ' ';
        }
        cout << '\n';
    }

    return 0;
}