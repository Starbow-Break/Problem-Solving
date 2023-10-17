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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N; ll K; cin >> N >> K;
    vector<ll> speed(N);
    for(int i = 0; i < N; i++) cin >> speed[i];
    sort(all(speed));
    
    ll ans = 1e18;
    for(int i = 1; i < N; i++) {
        ll cur = K/(speed[0]*i+speed[i]*(N-i)) + (K%(speed[0]*i+speed[i]*(N-i)) > 0);
        ans = min(ans, cur);
    }
    
    cout << ans;
    
    return 0;
}