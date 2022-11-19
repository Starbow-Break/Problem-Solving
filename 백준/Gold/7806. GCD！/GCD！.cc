#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<double, double> dd;

vector<int> prime;
bool isPrime[32000];

void getPrime() {
    fill(isPrime+2, isPrime+32000, true);
    for(int i = 4; i < 32000; i += 2) { isPrime[i] = false; }
    
    for(int i = 3; i < 32000; i += 2) {
        for(int j = i*2; j < 32000; j += i) {
            isPrime[j] = false;
        }
    }
    
    for(int i = 2; i < 32000; i++) {
        if(isPrime[i]) { prime.push_back(i); }
    }
}

int gcdFact(int n, int k) {
    int ret = 1;
    
    for(auto &p: prime) {
        if(k == 1) break;
        
        int cnt1 = 0; int cnt2 = 0;
        ll w = p;
        while(w <= (ll)n) {
            cnt1 += n/w;
            w *= p;
        }
        while(k > 1) {
            if(k%p) break;
            
            cnt2++; k /= p;
        }
        
        for(int i = 1; i <= min(cnt1, cnt2); i++) { ret *= p; }
    }
    
    if(k > 1) {
        if(n >= k) ret *= k;
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    getPrime();
    int n, k;
    while(cin >> n >> k) {
        if(n == 0) n = 1;
        cout << gcdFact(n, k) << '\n';
    }

    return 0;
}
