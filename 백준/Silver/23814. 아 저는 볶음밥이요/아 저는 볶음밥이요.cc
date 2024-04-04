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
    
    ll D, N, M, K; cin >> D >> N >> M >> K;
    N %= D; M %= D;
    if(N > M) swap(N, M);
    
    // 최대 군만두 수
    ll maxG = 0, temp = K;
    if(M > 0 && D-M <= temp) {
        maxG++; temp -= (D-M);
    }
    if(N > 0 && D-N <= temp) {
        maxG++; temp -= (D-N);
    }
    maxG += temp/D;
    
    ll ans = 0;
    if(K/D == maxG) ans = max(ans, K);
    if(M > 0 && D-M <= K && (K-D+M)/D+1 == maxG) ans = max(ans, K-D+M);
    if(N > 0 && M > 0 && D-M+D-N <= K && (K+M+N-2*D)/D+2 == maxG) ans = max(ans, K+M+N-2*D);
    
    cout << ans;
    
    return 0;
}