#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

ll c[21][21] = {0, };
ll dp[21][21][21] = {0, };

ll combination(int n, int m) {
    if(c[n][m] != 0) return c[n][m];
    
    if(n == m || m == 0) {
        c[n][m] = 1; return 1;
    }
    
    c[n][m] = combination(n-1, m)+combination(n-1, m-1);
    return c[n][m];
}

ll solve(int n, int l, int r) {
    if(dp[n][l][r] != 0) return dp[n][l][r];
    
    if(n == 0) return 1;
    if(l < 1 || r < 1) return 0;
    if(l == 1 && r == 1) return 0;
    
    ll ret = 0;
    
    for(int i = l; i <= n-r+1; i++) {
        for(int ll = 1; ll <= n-i-r+2; ll++) {
            for(int rr = 1; rr <= i-l+1; rr++) {
                ret += combination(n-1, i-1)*solve(i-1, l-1, rr)*solve(n-i, ll, r-1);
            }
        } 
    }
    
    dp[n][l][r] = ret;
    return dp[n][l][r];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    dp[1][1][1] = 1;
    dp[2][1][2] = 1; dp[2][2][1] = 1;
    
    int T; cin >> T;
    while(T--) {
        int n, l, r; cin >> n >> l >> r;
        cout << solve(n, l, r) << '\n';
    }

    return 0;
}