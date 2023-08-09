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

ll dp[31][31] = {0, };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int H, N; cin >> H >> N;
    int d = abs(H-N);
    
    for(int i = 0; i <= d; i++) {
        dp[0][i] = 1;
    }
    
    for(int c = 1; c <= d; c++) {
        for(int r = 1; r <= c; r++) {
            if(r == c) {
                dp[r][c] = dp[r-1][c];
            }
            else {
                dp[r][c] = dp[r-1][c]+dp[r][c-1];
            }
        }
    }
    
    cout << dp[d][d];
    
    return 0;
}