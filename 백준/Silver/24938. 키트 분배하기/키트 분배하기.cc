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
#define MOD 1'000'000'007

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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    int A[200000]; ll tot = 0;
    for(int i = 0; i < N; i++) {
        cin >> A[i]; tot += A[i];
    }
    
    int t = tot/N;
    
    ll ans = 0;
    for(int i = 0; i < N-1; i++) {
        if(A[i] < t) {
            int d = t-A[i];
            ans += d;
            A[i] += d; A[i+1] -= d;
        }
        else {
            int d = A[i]-t;
            ans += d;
            A[i] -= d; A[i+1] += d;
        }
    }
    
    cout << ans;

    return 0;
}