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

ll gcd(ll a, ll b) {
    if(a < b) swap(a, b);
    return (b ? gcd(b, a%b) : a);
}

ll lcm(ll a, ll b) {
    return a*b/gcd(a, b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;
    while(T--) {
        ll N; cin >> N;
        if(N%2) cout << lcm(lcm(N, N-1), N-2) << '\n';
        else {
            ll ans = 0;
            for(int i = 0; i <= min(N, 5ll); i++) {
                for(int j = i+1; j <= min(N, 5ll); j++) {
                    for(int k = j+1; k <= min(N, 5ll); k++) {
                        ans = max(ans, lcm(lcm(N-i, N-j), N-k));
                    }
                }
            }
            cout << ans << '\n';
        }
    }
    
    return 0;
}
