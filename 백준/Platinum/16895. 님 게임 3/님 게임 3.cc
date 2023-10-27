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
    int num[N+1]; num[0] = 0;
    for(int i = 1; i <= N; i++) cin >> num[i];
    
    int xorSum[N+1];
    xorSum[0] = 0;
    for(int i = 1; i <= N; i++) {
        xorSum[i] = xorSum[i-1]^num[i];
    }
    
    int ans = 0;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= num[i]; j++) {
            int grendy = (xorSum[N]^xorSum[i])^(xorSum[i-1])^(num[i]-j);
            ans += (grendy == 0);
        }
    }
    
    cout << ans;
    
    return 0;
}