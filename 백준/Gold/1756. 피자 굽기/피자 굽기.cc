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
    
    int D, N; cin >> D >> N;
    int radius[D+1];
    radius[0] = 1'000'000'000;
    for(int i = 1; i <= D; i++) {
        int v; cin >> v;
        radius[i] = min(radius[i-1], v);
    }
    
    int ans = D+1;
    while(ans >= 1 && N--) {
        int r; cin >> r;
        ans--;
        while(radius[ans] < r) ans--;
    }
    
    cout << ans;
    
    return 0;
}