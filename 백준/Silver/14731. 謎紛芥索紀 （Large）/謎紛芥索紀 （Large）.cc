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

ll modPow(int a, int e) {
    ll ret = 1, w = a;
    while(e > 0) {
        if(e&1) {
            ret *= w; ret %= MOD;
        }
        w *= w; w %= MOD;
        e >>= 1;
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    ll ans = 0;
    while(N--) {
        int C, K; cin >> C >> K;
        ans += 1LL*C*K%MOD*modPow(2, K-1)%MOD;
        ans %= MOD;
    }
    
    cout << ans;

    return 0;
}