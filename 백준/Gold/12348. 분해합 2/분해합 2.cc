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

ll solve(ll N) {
    ll ret = 0;
    
    for(int i = 1; i <= 162; i++) {
        ll M = N-i;
        ll cur = M;
        while(M > 0) {
            cur += M%10;
            M /= 10;
        }
        
        if(N == cur) {
            if(ret) ret = min(ret, N-i);
            else ret = N-i;
        }
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll N; cin >> N;
    cout << solve(N);
    
    return 0;
}