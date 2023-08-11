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
    
    int X, K; cin >> X >> K;
    int cntL[10001] = {0, };
    int cntR[10001] = {0, };
    
    repeat(X) {
        int v; cin >> v;
        cntL[v]++;
    }
    
    repeat(X) {
        int v; cin >> v;
        cntR[v]++;
    }
    
    ll ans = 1LL*X*X;
    for(int i = 1; i <= K; i++) {
        ans -= 1LL*cntL[i]*cntR[i];
    }
    
    cout << ans;
    
    return 0;
}