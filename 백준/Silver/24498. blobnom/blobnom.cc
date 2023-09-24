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
    
    int N; cin >> N;
    vector<int> h;
    repeat(N) {
        int v; cin >> v;
        h.pb(v);
    }
    
    if(N == 1) {
        cout << h[0];
        return 0;
    }
    if(N == 2) {
        cout << max(h[0], h[1]);
        return 0;
    }
    
    int ans = 0;
    for(int i = 1; i < N-1; i++) {
        ans = max(ans, h[i]+min(h[i-1], h[i+1]));
    }
    ans = max({ans, h[0], h[N-1]});
    cout << ans;
    
    return 0;
}
