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

ll C[20][20];
ll dp[21][2];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    C[0][0] = 1;
    for(int i = 1; i < 20; i++) {
        for(int j = 0; j <= i; j++) {
            if(j == 0 || j == i) {
                C[i][j] = 1;
            }
            else {
                C[i][j] = C[i-1][j-1]+C[i-1][j];
            }
        }
    }
    
    dp[0][0] = 1; dp[0][1] = 1;
    dp[1][0] = 1; dp[1][1] = 1;
    
    for(int i = 1; i <= 20; i++) {
        for(int j = 0; j < i; j++) {
            if(j%2) dp[i][0] += C[i-1][j]*dp[j][0]*dp[i-1-j][0];
            else dp[i][1] += C[i-1][j]*dp[j][1]*dp[i-1-j][0];
        }
    }
    
    int T; cin >> T;
    while(T--) {
        int v; cin >> v;
        if(v == 1) cout << 1 << '\n';
        else cout << dp[v][0]+dp[v][1] << '\n';
    }
    
    return 0;
}