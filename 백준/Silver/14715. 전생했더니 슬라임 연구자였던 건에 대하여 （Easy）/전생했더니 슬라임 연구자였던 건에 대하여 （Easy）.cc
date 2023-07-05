#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <map>
#include <iomanip>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef __int128_t int128;

vector<int> primes;
bool isPrime[1000001];
void getPrimes() {
    fill(isPrime+2, isPrime+1000001, true);
    for(int i = 2; i <= 1000000; i++) {
        if(isPrime[i]) {
            primes.push_back(i);
            for(int j = 2*i; j <= 1000000; j += i)
                isPrime[j] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    getPrimes();
    
    int K; cin >> K;
    int cnt = 0;
    for(auto &p: primes) {
        if(K == 1) break;
        while(!(K%p)) {
            K /= p; cnt++;
        }
    }
    
    int ans = 0, w = 1;
    while(cnt > w) {
        ans++; w *= 2;
    }
    cout << ans;

    return 0;
}