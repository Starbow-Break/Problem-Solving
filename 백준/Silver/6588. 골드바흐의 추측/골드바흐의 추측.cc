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
#define MOD 1'000'000'009

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

vector<int> primes;
bool isPrime[1'000'001] = {false, };
int arr[1'000'001];

void getPrimes() {
    fill(isPrime+2, isPrime+1'000'001, true);
    for(int i = 2; i <= 1'000'000; i++) {
        if(isPrime[i]) {
            if(i > 2) primes.push_back(i);
            for(int j = 2*i; j <= 1'000'000; j += i) isPrime[j] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    getPrimes();
    
    for(int i = 6; i <= 1'000'000; i += 2) {
        for(auto &p: primes) {
            if(isPrime[i-p]) {
                arr[i] = p;
                break;
            }
        }
    }
    
    int N;
    while(cin >> N) {
        if(!N) break;
        cout << N << " = " << arr[N] << " + " << N-arr[N] << '\n';
    }
    
    return 0;
}