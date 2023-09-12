#include <bits/stdc++.h>
#define fi first
#define se second
#define repeat(n) for(int i = 0; i < n; i++)
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define pb push_back
#define all(vec) vec.begin(), vec.end()
#define rall(vec) vec.rbegin(), vec.rend()
#define compress(vec) sort(all(vec)); vec.erase(unique(all(vec)), vec.end());

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;
using int128 = __int128_t;

int modPow(int a, int e, int mod) {
    ll ret = 1, w = a;
    while(e > 0) {
        if(e%2) {
            ret *= w; ret %= mod;
        }
        e /= 2;
        w *= w; w %= mod;
    }
    return ret;
}

int solve(int A, int N, int P) {
    ll ret = A%P;
    for(int i = 2; i <= N; i++) {
        ret = modPow(ret, i, P);
        ret %= P;
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T; cin >> T;
    for(int tc = 1; tc <= T; tc++) {
        int A, N, P; cin >> A >> N >> P;
        cout << "Case #" << tc << ": " << solve(A, N, P) << '\n';
    }
    
    return 0;
}
