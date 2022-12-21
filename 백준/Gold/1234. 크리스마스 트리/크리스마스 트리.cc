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

ll dp[11][101][101][101] = {0, };
ll c[11][11] = {0, };

ll combination(int n, int m) {
    if(c[n][m] != 0) return c[n][m];
    
    if(m == 0 || n == m) {
        c[n][m] = 1; return 1;
    }
    
    c[n][m] = combination(n-1, m)+combination(n-1, m-1);
    return c[n][m];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, r, g, b; cin >> N >> r >> g >> b;
    dp[0][r][g][b] = 1;
    for(int n = 1; n <= N; n++) {
        for(int br = 0; br <= r; br++) {
            for(int bg = 0; bg <= g; bg++) {
                for(int bb = 0; bb <= b; bb++) {
                    if(br >= n) dp[n][br-n][bg][bb] += dp[n-1][br][bg][bb];
                    if(bg >= n) dp[n][br][bg-n][bb] += dp[n-1][br][bg][bb];
                    if(bb >= n) dp[n][br][bg][bb-n] += dp[n-1][br][bg][bb];
                    
                    if(!(n%2)) {
                        if(br >= n/2 && bg >= n/2)
                            dp[n][br-n/2][bg-n/2][bb] += combination(n, n/2)*dp[n-1][br][bg][bb];
                        if(br >= n/2 && bb >= n/2)
                            dp[n][br-n/2][bg][bb-n/2] += combination(n, n/2)*dp[n-1][br][bg][bb];
                        if(bg >= n/2 && bb >= n/2)
                            dp[n][br][bg-n/2][bb-n/2] += combination(n, n/2)*dp[n-1][br][bg][bb];
                    }
                    
                    if(!(n%3)) {
                        if(br >= n/3 && bg >= n/3 && bb >= n/3)
                            dp[n][br-n/3][bg-n/3][bb-n/3] += combination(n, n/3)*combination(2*n/3, n/3)*dp[n-1][br][bg][bb];
                    }
                }
            }
        }
    }
    
    ll ans = 0;
    for(int rr = 0; rr <= r; rr++) {
        for(int gg = 0; gg <= g; gg++) {
            for(int bb = 0; bb <= b; bb++) {
                ans += dp[N][rr][gg][bb];
            }
        }
    }
    
    cout << ans;

    return 0;
}