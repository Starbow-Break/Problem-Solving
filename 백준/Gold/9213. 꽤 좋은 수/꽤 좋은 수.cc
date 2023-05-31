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

vector<int> primes;
bool isPrime[1000];
int bad[1'000'001] = {0, };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    for(int i = 1; i <= 1'000'000; i++) {
        for(int j = i*2; j <= 1'000'000; j += i) bad[j] += i;
    }
    
    for(int i = 1; i <= 1'000'000; i++) bad[i] = abs(i-bad[i]);
    
    int start, stop, badness; int tc = 0;
    while(cin >> start >> stop >> badness) {
        if(!start && !stop && !badness) break;
        
        tc++; int ans = 0;
        for(int i = start; i <= stop; i++) {
            ans += (badness >= bad[i]);
        }
        
        cout << "Test " << tc << ": " << ans << '\n';
    }

    return 0;
}