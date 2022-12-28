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

ll dp[68];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    dp[0] = 1; dp[1] = 1; dp[2] = 2; dp[3] = 4;
    for(int i = 4; i <= 67; i++) {
        dp[i] = dp[i-1]+dp[i-2]+dp[i-3]+dp[i-4];
    }
    
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        cout << dp[n] << '\n';
    }

    return 0;
}