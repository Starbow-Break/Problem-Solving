#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <list>
#include <map>
#include <cmath>
#include <iomanip>
#define MOD 1000000007

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

ll dp[101][101][101] = {0, };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    dp[1][1][1] = 1;
    for(int n = 2; n <= 100; n++) {
        for(int l = 1; l <= n; l++) {
            for(int r = 1; r <= n; r++) {
                dp[n][l][r] += dp[n-1][l-1][r];
                dp[n][l][r] += dp[n-1][l][r-1];
                dp[n][l][r] += dp[n-1][l][r]*(n-2);
                dp[n][l][r] %= MOD;
            }
        }
    }
    
    int N, L, R; cin >> N >> L >> R;
    cout << dp[N][L][R];

    return 0;
}