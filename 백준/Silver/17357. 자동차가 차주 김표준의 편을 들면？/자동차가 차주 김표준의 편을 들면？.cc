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
    ll sum[N+1], sqSum[N+1];
    sum[0] = sqSum[0] = 0;
    
    for(int i = 1; i <= N; i++) {
        int v; cin >> v;
        sum[i] = sum[i-1]+v;
        sqSum[i] = sqSum[i-1]+1LL*v*v;
    }
    
    for(int k = 1; k <= N; k++) {
        int ans = 0; ll value = -1;
        for(int i = 1; i <= N-k+1; i++) {
            ll curValue = k*(sqSum[i+k-1]-sqSum[i-1])-(sum[i+k-1]-sum[i-1])*(sum[i+k-1]-sum[i-1]);
            if(value < curValue) {
                ans = i; value = curValue;
            }
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}