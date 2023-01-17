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

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

bool dp[21][1001] = {false, };

int solve(int N) {
    dp[0][0] = true;
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j <= 1000; j++) {
            if(dp[i][j]) {
                dp[i+1][j+1] = true; dp[i+1][j+5] = true;
                dp[i+1][j+10] = true; dp[i+1][j+50] = true;
            }
        }
    }
    
    int ans = 0;
    for(int j = 0; j <= 1000; j++) { ans += dp[N][j]; }
    
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    cout << solve(N);

    return 0;
}